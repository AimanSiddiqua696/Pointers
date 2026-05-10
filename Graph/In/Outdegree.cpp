#include <iostream>
#include <vector>
using namespace std;
// function to find out degree 
int outDegree(vector<int> adjList[], int vertex){
    return adjList[vertex].size();
}
 // function to find in degree
 int inDegree(vector<int> adjList[], int vertices, int vertex){
    int count = 0;
    for (int i = 0; i < vertices; i++){
        for(int j = 0; j < adjList[i].size(); j++){
            if (adjList[i][j] == vertex){
                count ++;
            }
        }
    }
    return count;
 }
 int main(){
    int edges, vertices;
    cout<<"Enter vertices : ";
    cin>> vertices;
    cout << "Enter edges : ";
    cin>> edges;
    //create directed graph adjacency list
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

    // Input vertex
    int vertex;
    cout << "Enter vertex : ";
    cin>> vertex;

    cout << "In-Degree of vertex "<< vertex <<" = "
    << inDegree(adjList, vertices, vertex) << endl;
    cout << "Out-Degree of vertex "<< vertex <<" = "
    << outDegree(adjList,vertex) << endl;
    return 0;


}