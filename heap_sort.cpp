#include <iostream>
#include <vector>
#include <algorithm> 

// Function to maintain the max-heap property
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Recursively heapify
    }
}

// Main function to perform heap sort
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    std::vector<int> data = {12, 11, 13, 5, 6, 7};

    std::cout << "Original array: ";
    for (int i : data) std::cout << i << " ";
    
    heapSort(data);

    std::cout << "\nSorted array:   ";
    for (int i : data) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}

