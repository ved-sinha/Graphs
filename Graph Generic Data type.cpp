#include<iostream>
#include<list>
#include<cstring>
#include<map>
#define ll long long int
using namespace std;

template<typename T>
class Graph {
    map<T,list<T>> adjList;
public:
   //we are not taking number of vertices now
    Graph(){
        
    };
    
    void addEdge(T u,T v,bool bidir=true) {
        adjList[u].push_back(v);
        if(bidir) {
            adjList[v].push_back(u);
        }
    }
    
    void printEdge() {
        
        //Here instead of auto, we could have written pair<T, list<T>> becuase
        //row is Delhi->amristar,banaglore,bihar so it is pair of string and
        //List of strings.
        
        for(auto row:adjList) {
            T key=row.first;
            cout<<key<<"->";
            for(auto ele:row.second) {
                cout<<ele<<",";
            }
            cout<<endl;
        }
    }
};

int main() {
	Graph<string> g;
	g.addEdge("A","D");
	g.addEdge("A","J");
	g.addEdge("D","S");
	g.addEdge("D","B");
	g.printEdge();
}
