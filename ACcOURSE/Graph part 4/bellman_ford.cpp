#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include <climits>

using namespace std;

class Edge{
public: 
    int v ;
    int wt;

    Edge(int v, int wt){
        this->v = v;
        this ->  wt = wt;

    }

    

};

void dijkstra(int src, vector<vector<Edge>> graph,int V){
    priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>> pq; //min heap
    
    vector<int> dist(V,INT_MAX);

    pq.push(make_pair(0,src));
    dist[src] = 0;

    while(pq.size() > 0){
        int u = pq.top().second;
        pq.pop();

        vector<Edge> edges = graph[u];

        for(Edge e : edges){//e.v, e.wt
            if(dist[e.v] > dist[u] + e.wt){
                dist[e.v] = dist[u] + e.wt;
                pq.push(make_pair(dist[e.v],e.v));
            }
        }

        

    }
    for(int d : dist){
            cout << d << " " ;
        }
        cout << endl;
}


void bellman_ford(vector<vector<Edge>> graph, int V, int src){
    vector<int> dist(V,INT_MAX);
    dist[src] = 0;


    for(int i = 0; i < V-1; i++){
        for(int u = 0; u < V; u++){
            for(Edge e : graph[u]){
                if(dist[e.v] > dist[u] + e.wt){
                    dist[e.v] = dist[u] + e.wt;
                }
            }
        }
    }

    for(int d : dist){
        cout << d << " " ;
    }
    cout << endl;
}

int main(){
    int V = 5;
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(2,-4));
    graph[2].push_back(Edge(3,2));
    
    graph[3].push_back(Edge(4,4));
    
    graph[4].push_back(Edge(1,-1));
    
    


    bellman_ford(graph,5,0);
    return 0;
}