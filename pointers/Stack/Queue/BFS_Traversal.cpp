#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(){
int V = 6;
vector<int> adj[7];
adj[1] = {2, 3};
adj[2] = {4, 5};
adj[3] = {6};
vector<bool> visited(7, false);
queue <int> q;
q.push(1);
visited[1] = true;
while (!q.empty()){
    int node = q.front();
    q.pop();
    cout<< node <<" ";
    for (int neighbor : adj[node]){
        if(!visited[neighbor]){
            q.push(neighbor);
            visited[neighbor] = true;
        }
    }
}
return 0;
}