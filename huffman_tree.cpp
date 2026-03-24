#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// A Huffman tree node
struct Node {
    char data;
    unsigned freq;
    Node *left, *right;

    Node(char data, unsigned freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// Comparison object to create a Min-Heap
struct compare {
    bool operator()(Node* l, Node* r) {
        return (l->freq > r->freq);
    }
};

// Traverses the tree to store Huffman codes in a map
void storeCodes(Node* root, string str, map<char, string>& huffmanCode) {
    if (!root) return;
    if (root->data != '$') huffmanCode[root->data] = str;

    storeCodes(root->left, str + "0", huffmanCode);
    storeCodes(root->right, str + "1", huffmanCode);
}

void buildHuffmanTree(char data[], int freq[], int size) {
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new Node(data[i], freq[i]));

    while (minHeap.size() != 1) {
        Node *left = minHeap.top(); minHeap.pop();
        Node *right = minHeap.top(); minHeap.pop();

        // '$' is a special value for internal nodes
        Node *top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    map<char, string> huffmanCode;
    storeCodes(minHeap.top(), "", huffmanCode);

    cout << "Huffman Codes:\n";
    for (auto const& [key, val] : huffmanCode)
        cout << key << ": " << val << endl;
}

int main() {
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(arr) / sizeof(arr[0]);

    buildHuffmanTree(arr, freq, size);
    return 0;
}
