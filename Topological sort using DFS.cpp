#include<bits/stdc++.h>
#define ll long long int
using namespace std;

template<typename T>
class Graph {
    
    map<T,list<T>> adjList;

public:

    Graph() {};
    
    void addEdge(T u,T v,bool bidir) {
        adjList[u].push_back(v);
        if(bidir) 
            adjList[v].push_back(u);
    }
    
    void printEdge() {
        for(auto node:adjList) {
            cout<<node.first<<" -> ";
            for(auto x:node.second) {
                cout<<x<<",";
            }
            cout<<endl;
        }
    }
    
    void dfsHelper(T node,map<T,bool> &visited,list<T> &ordering) {
        visited[node]=true;
        
        for(auto neighour:adjList[node]) {
            if(!visited[neighour]) {
                dfsHelper(neighour,visited,ordering);
            }
        }
        
        //Its a tail call so automatically the last element will be at last
        //and first at first
        
        ordering.push_front(node);
    }
    
    void dfs() {
        
        map<T,bool>visited;
        list<T> ordering;
        
        for(auto i:adjList) {
            if(!visited[i.first]) {
                dfsHelper(i.first,visited,ordering);
            }
        }
        
        //Print ordering
        
        cout<<endl;
        
        for(auto x:ordering) {
            cout<<x<<" -> ";
        }
        
        cout<<endl;
        
    }
    
};

int main() {
	Graph<int> g;
	g.addEdge(0,2,false);
	g.addEdge(1,2,false);
	g.addEdge(1,4,false);
	g.addEdge(2,3,false);
	g.addEdge(4,5,false);
	g.addEdge(3,5,false);
	g.printEdge();
	g.dfs();
	
}
