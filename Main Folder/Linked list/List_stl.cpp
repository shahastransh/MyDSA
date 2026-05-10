#include<iostream>
#include<list>
#include<iterator>
using namespace std;


void printList(list<int> ll){
    list<int> :: iterator itr;
    for(itr = ll.begin(); itr != ll.end(); itr++){
        cout << (*itr) << " -> ";
    }
    cout << " NULL "<< endl;
}
int main(){
    list<int> ll;

    ll.push_back(2);
    ll.push_front(1);
    ll.push_back(3);
    ll.push_back(4);

    printList(ll);

    cout << ll.size() <<endl;

    cout << ll.front() <<endl;

    cout << ll.back() <<endl;

    ll.pop_back();
    printList(ll);

    ll.pop_front();
    printList(ll);
    
    
    return 0;
}