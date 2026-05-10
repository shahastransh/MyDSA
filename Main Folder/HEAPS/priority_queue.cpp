#include<iostream>
#include<queue>
using namespace std;

int main(){

    // for max heap :-


    priority_queue<int> pq;

    //for using min heap :-

    priority_queue<int,vector<int>,greater<int>> pq;


    pq.push(5);
    pq.push(10);
    pq.push(6);
    pq.push(9);
    pq.push(7);
    pq.push(2);

    while(!pq.empty()){
        cout << " top " << pq.top() << endl;
        pq.pop();
    }   
    return 0;
}