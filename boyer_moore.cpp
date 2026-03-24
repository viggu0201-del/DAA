#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define NO_OF_CHARS 256

// Preprocessing: Create bad character table
void badCharHeuristic(const string& pat, int size, int badchar[NO_OF_CHARS]) {
    for (int i = 0; i < NO_OF_CHARS; i++) badchar[i] = -1;
    for (int i = 0; i < size; i++) badchar[(int)pat[i]] = i;
}

// Search for pattern in text
void search(const string& txt, const string& pat) {
    int m = pat.size(), n = txt.size(), badchar[NO_OF_CHARS];
    badCharHeuristic(pat, m, badchar);
    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && pat[j] == txt[s + j]) j--;
        if (j < 0) {
            cout << "Pattern at shift = " << s << endl;
            s += (s + m < n) ? m - badchar[(int)txt[s + m]] : 1;
        } else s += max(1, j - badchar[(int)txt[s + j]]);
    }
}
