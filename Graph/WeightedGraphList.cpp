#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main(){
    int vertices, edges;
    cout <<"Enter number of vertices : ";
    cin >> vertices;
    cout <<"Enter number of edges : ";
    cin >> edges;

   

    //weighted Adjacency list
    vector <pair<int , int>> adjList[100];

    //input edges with weights:
    cout<< "Enter edges (source destination weight):" <<endl;
    for (int i = 0; i < edges; i++){
        int u, v, weight;
        cin >> u >> v >>weight;

        
        //store in adjacency list
        adjList[u].push_back({v, weight});

    }

    
// display weighted Adjacency List
cout << "Weighted Adjacency List: " <<endl;
for (int i = 0; i < vertices; i++){
    cout << i <<" -> ";
    for (int j = 0; j < adjList[i].size(); j++){
        cout << "("
        <<adjList[i][j].first
        <<", "
        <<adjList[i][j].second
        << ")";
    }
    cout << endl;
}
return 0;
}
