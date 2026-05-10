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

    //weighted Adjacency matrix
    int adjMatrix[100][100];

    //initialize matrix with 0
    for (int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            adjMatrix[i][j] = 0;
        }
    }

  

    //input edges with weights:
    cout<< "Enter edges (source destination weight):" <<endl;
    for (int i = 0; i < edges; i++){
        int u, v, weight;
        cin >> u >> v >>weight;

        // store weight in matrix
        adjMatrix[u][v] = weight;
        
    }

    //display weighted adjacency matrix
    cout << " Weighted Adjacency Matrix: "<< endl;
      for (int i = 0 ; i < vertices; i++){
      for (int j = 0 ; j < vertices; j++){
        cout << setw(3) << adjMatrix[i][j] <<" ";
      }
      cout<< endl;

}
return 0;
}
