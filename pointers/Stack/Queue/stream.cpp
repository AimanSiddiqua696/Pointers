#include <iostream>
#include <queue>
using namespace std;

int main() {
    string stream = "aabc";
    queue<char> q;
    int freq[26] = {0};

    for (char ch : stream) {
        freq[ch - 'a']++;
        q.push(ch);

        // Remove repeating characters
        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }

    return 0;
}