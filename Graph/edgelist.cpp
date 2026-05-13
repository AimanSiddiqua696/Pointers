#include <iostream>
#include <vector>
using namespace std;
int main(){
    int vertices , edges;
    cout << " Enter number of vertices : ";
    cin >> vertices;
    cout <<" Enter number of edges : ";
    cin >> edges;
    // Vector to store adge list
    vector<pair<int, int>> edgeList ;
    //input edges
    cout<< " Enter edges (u , v):" <<endl;
    for (int i = 0; i < edges ; i++){
        int u, v; 
        cin >> u >> v;
         // store edge as pair
         edgeList.push_back({u, v});
    }
    // display edge list
    cout<<" Edge List: " << endl;

    for (int i = 0; i < edgeList.size(); i++){
        cout<< "("
        << edgeList[i].first
        << ","
        << edgeList[i].second
        << ")" <<endl;
    }
    return 0;

}