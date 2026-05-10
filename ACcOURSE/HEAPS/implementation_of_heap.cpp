#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Heap{
    vector<int> vec;
public:
    void push(int val){
        //insert
        vec.push_back(val);

        //fix
        int x = vec.size()-1; // child idx
        int parI = (x - 1)/2; //par IDX

        while(parI >= 0 && vec[x] >  vec[parI]){ //O(logn)
            swap(vec[parI] , vec[x]);
            x = parI;
            parI = (x-1)/2;
        }
    }

    void heapify(int i){// pass the root or parI
        if(i > vec.size()){
            return;
        }
        int l = 2*i+1;
        int r = 2*i+2;

        int maxI = i;
         
        if (l < vec.size() && vec[l] > vec[maxI])
        {
            maxI = l;
        }

        if (r < vec.size() && vec[r] > vec[maxI])
        {
            maxI = r;
        }

        swap(vec[i],vec[maxI]);
        if(maxI != i){
            heapify(maxI);
        }
        

    }

    void pop(){
        //step 1 -> swap(root,lastIdx)
        swap(vec[0], vec[vec.size()-1]);

        //step 2 - delete last idx
        vec.pop_back();

        //step 3 - > heapify
        heapify(0);
    }

    int top(){
        return vec[0];

    }

    bool empty(){
        return vec.size() == 0; 
    }
};

int main(){

    Heap heap;
    heap.push(100);
    heap.push(20);
    heap.push(30);
    heap.push(40);


    while(!heap.empty()){
        cout << heap.top() << endl;
        heap.pop();
    }
    
    return 0;
}