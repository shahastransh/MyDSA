#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

struct comparePair{
    bool operator()(pair<string,int> &p1,pair<string,int> &p2){
        return p1.second < p2.second;
    }
};

int main(){
    priority_queue<pair<string,int>, vector<pair<string,int>>,comparePair> pq;

    pq.push(make_pair("aman",85));
    pq.push(make_pair("B",90));
    pq.push(make_pair("C",83));

    while(!pq.empty()){
        cout<<pq.top().first << ", " << pq.top().second << endl;
        pq.pop(); 
    }
    
    
    return 0;
}