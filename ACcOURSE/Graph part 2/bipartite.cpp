#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int>* l;
    bool isUndir;
public:
    Graph(int V,bool isUndir = true){
        this -> V =V;
        l = new list<int> [V];
        this->isUndir = isUndir;
       
    }

    void addEdge(int u, int v){// u---v
        l[u].push_back(v);
        if(isUndir){
            l[v].push_back(u);
        }
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

    bool directedCycleHelper(int src,vector<bool> vis, vector<bool> recPath ){
        vis[src] = true;
        recPath[src] = true;

        list<int> neighbor = l[src];
        for(int v : neighbor){
            if(!vis[v]){
                if(directedCycleHelper(v,vis,recPath)){
                    return true;
                }
            }else{
                if(recPath[v]){
                    return true;
                }
            }
            
        }
        recPath[src] = false;
        return false;
    }


    bool isCycleDirected(){
        vector<bool> vis(V,false);
        vector<bool> recPath(V,false);
        for(int i = 0; i<V;i++){
            if(!vis[i]){
                if( directedCycleHelper(0,vis,recPath)){
                    return true;
                } 

            }
        }
        
        return false;
    }

    bool bipartiteHelper(int src){
        vector<int> vis(V,false);
        queue<int> q;
        vector<int> color(V,-1);
        q.push(src);
        vis[src] = true;
        color[0] = 0;
        while(q.size() > 0){
            int curr = q.front();
            q.pop();
            list<int> neighbors = l[curr];
            for(int v : neighbors){
                if(!vis[v]){
                    vis[v] = true;
                    color[v] = !color[curr];
                    q.push(v);
                }else{
                    if(color[v] == color[curr]){
                        return false;
                    }
                }
                
            }
        }

        return true;
    }
                
    

    bool isBipartite(){
        return bipartiteHelper(0);
    }

    
};

int main(){
    int V=5;
    Graph graph(5);

    graph.addEdge(1,0);
    graph.addEdge(0,2);
    graph.addEdge(2,3);
    graph.addEdge(3,2);
    

    graph.print();
    cout << endl;

    cout << graph.isBipartite();

    

    
    
    
    return 0;
}