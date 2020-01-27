#include<iostream>
#include<map>
#include<queue>
#include<list>
#include<stack>
#include<climits>
#define ll long long int
using namespace std;

template <typename T>
class Graph {
    
    map<T,list<T>> adjList;
    
public: 
   
    Graph(){};
    
    void addEdge(T u,T v,bool bidir=true) {
        adjList[u].push_back(v);
        if(bidir) 
            adjList[v].push_back(u);
    } 
    
    void printList() {
        for(auto row:adjList) {
            cout<<row.first<<" -> ";
            for(auto elements:row.second) {
                cout<<elements<<" , ";
            }
            cout<<endl;
        }
    }
    
    void bfs(T src) {
        
        queue<T> Q;
        map<T,int> distance;
        map<T,T> parent;
        
        for(auto i:adjList) {
            distance[i.first]=INT_MAX;
        }
        
        Q.push(src);
        distance[src]=0;
        parent[src]=src;
        
        while(!Q.empty()) {
            T node=Q.front();
            //cout<<node<<" ";
            Q.pop();
            
            for(auto neighour:adjList[node]) {
                if(distance[neighour]==INT_MAX) {
                    Q.push(neighour);
                    distance[neighour]=distance[node]+1;
                    parent[neighour]=node;
                }
            }
        }
        
        //Printing the distances by order of nodes
        
        for(auto dist:distance) {
            cout<<dist.first<<" "<<dist.second<<"\n";
        }
        
        //Printing the distance be order of nodes in Graph
        cout<<endl;
        
        for(auto x:adjList) {
            cout<<x.first<<" "<<distance[x.first]<<"\n";
        }
    }
    
    void dfsHelper(T node, map<T,bool> &visited) {
        visited[node]=true;
        cout<<node<<" ";
        
        for(T neighour:adjList[node]) {
            if(!visited[neighour]) 
                dfsHelper(neighour,visited);
        }
    }
    
    void dfs(T src) {
        map<T,bool> visited;
        dfsHelper(src,visited);
    }
    
};

int main() {
	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(2,4);
	g.addEdge(3,4);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.printList();
	cout<<endl;
//	g.bfs(0);
	cout<<endl;
	g.dfs(0);
	return 0;
}
