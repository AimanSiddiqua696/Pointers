#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start, vector<int> adj[], int n) {
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n = 5;
    vector<int> adj[5];

    // Graph edges
    adj[0] = {1, 3};
    adj[1] = {2, 4};
    adj[2] = {};
    adj[3] = {};
    adj[4] = {};

    BFS(0, adj, n);

    return 0;
}