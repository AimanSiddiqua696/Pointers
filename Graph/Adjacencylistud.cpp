#include <iostream>
#include <vector>
using namespace std;
int main(){
    int edges, vertices;
    cout<<"Enter vertices : ";
    cin>> vertices;
    cout << "Enter edges : ";
    cin>> edges;
    //create adjacency list
    vector<int> adj[100];

    //input edges
    cout<<"Enter edges (u, v):"<<endl;
    for (int i = 0; i < edges ; i++){
        int u , v;
        cin >> u >> v;
        // graph is undirected
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    //display adjacency  list
    cout << " Adjacency List : "<< endl;
    for (int i = 0; i < vertices ; i++){
        cout << i;
        for (int j = 0; j < adj[i].size(); j++){
            cout <<" ->" << adj[i][j];
        }
        cout<< endl;
    }
    return 0;


}