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
    vector<int> adjList[100];

    //input edges
    cout<<"Enter edges (u, v):"<<endl;
    for (int i = 0; i < edges ; i++){
        int u , v;
        cin >> u >> v;
        // graph is undirected
        adjList[u].push_back(v);
      

    }
    //display adjacency  list
    cout << " Adjacency List : "<< endl;
    for (int i = 0; i < vertices ; i++){
        cout << i <<"->";
        for (int j = 0; j < adjList[i].size(); j++){
            cout <<" ->" << adjList[i][j];
        }
        cout<< endl;
    }
    return 0;


}