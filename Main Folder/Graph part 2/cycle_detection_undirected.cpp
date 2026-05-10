#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int>* l;
public:
    Graph(int V){
        this -> V =V;
        l = new list<int> [V];
       
    }

    void addEdge(int u, int v){// u---v
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int i = 0; i<V; i++){
            list<int> neighbors = l[i];
            cout << i << " : " ;
            for(int v : neighbors){
                cout << v << " " ;
            }
            cout << endl;
        }
    }

    bool undirectedCycleHelper(int src, vector<bool> vis, int par){//O(v+e)
        vis[src] = true;
        list<int> neighbors = l[src];
        for(int v : neighbors){
            if(!vis[v]){
                if(undirectedCycleHelper(v,vis,src)){
                    return true;
                }
            }else{
                if(v != par){ //cycle condition
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycleUndirected(){
        vector<bool> vis(V,false);
        return undirectedCycleHelper(0,vis,-1);
    }

    
};

int main(){
    int V=5;
    Graph graph(5);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(0,3);
    graph.addEdge(1,2);
    graph.addEdge(3,4);
    

    graph.print();

    cout << endl;

    cout << graph.isCycleUndirected();
    
    
    return 0;
}