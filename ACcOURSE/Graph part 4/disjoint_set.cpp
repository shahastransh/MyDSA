#include<iostream>
#include<vector>
using namespace std;


class DisjointSet{
public:
    int n;
    vector<int> parr;
    vector<int>rank;

    DisjointSet(int n){
        this -> n = n;
        
        for(int i= 0; i< n; i++){
            parr.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x){
        if(parr[x] == x){
            return x;
        }

        return parr[x] = find(parr[x]); //compression optimisation
    }


    void unionByRank(int a, int b){
        int parA = find(a);
        int parB = find(b);

        if(rank[parA] == rank[parB]){//A parent of B
            parr[parB] = parA;
            rank[parA]++;
        }else if(rank[parA] > rank[parB]){
            parr[parB] = parA;
        }else{
            parr[parA] = parB;

        }
    }

    void getInfo(){
        for(int i = 0; i < n; i++){
            cout << i << " : " <<  parr[i] << ",  " << rank[i] << endl;
        }

        return;
    }
};
int main(){
    DisjointSet dj(6);
    dj.unionByRank(0,2);
    cout << dj.find(2) << endl; 
    dj.unionByRank(1,3);
    dj.unionByRank(2,5);
    dj.unionByRank(0,3);
    cout << dj.find(2) << endl;
    dj.unionByRank(0,4);

    dj.getInfo();

    return 0;
}