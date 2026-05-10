#include<iostream>
#include<vector>
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
};

int main(){
    Graph graph(5);

    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(2,3);
    graph.addEdge(2,4);
    graph.addEdge(3,1);

    graph.print();
    return 0;
}