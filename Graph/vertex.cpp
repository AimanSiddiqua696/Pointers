#include <iostream>
#include <vector>
using namespace std;
// function to find degree of a vertex
int findDegree(vector<int> adjList[], int vertex){
    return adjList[vertex]. size();
}

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

    // undirected graph 
    for (int i = 0; i < edges ; i++){
        int u , v;
        cin >> u >> v;
        // graph is undirected
        adjList[u].push_back(v);
        adjList[v].push_back(u);

    }
    //display adjacency  list
    cout << " Adjacency List : "<< endl;
    for (int i = 0; i < vertices ; i++){
        cout << i <<"->";
        for (int j = 0; j < adjList[i].size(); j++){
            cout <<" ->" << adjList[i][j] <<" ";
        }
        cout<< endl;
    }
    //find degree of a vertex
    int vertex;
    cout << " Enter vertex to find degree: ";
    cin >> vertex;
    cout<< " Degree of vertex " << vertex <<" = "
    << findDegree(adjList, vertex);
    return 0;


}