#include <iostream>
using namespace std;
int main(){
    int vertices, edges;
    cout <<" Enter number of vertices : ";
    cin>> vertices;
    cout<<"Enter number of edges : ";
    cin >> edges;
    //CREATE ADJACENCY MATRIX AND INITIALIZE WITH 0
    int adj[100][100] = {0};
    //input edges
    cout <<"Enter edges (u v): " << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin>>u >> v;

        // graph is undirected
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    // display adjacency matrix
    cout << "\nAdjacency matrix: " << endl;

    for (int i = 0; i < vertices; i++){
        for (int j = 0; j < vertices; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;

}