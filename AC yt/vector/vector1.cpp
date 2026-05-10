#include<iostream>
#include<vector>
using namespace std;

int main(){

    // initiation
    vector<int>vec = {1,2,3};
    cout<<vec[1]<<endl;
    vector<int>a( 3,0);
    cout << a[0] << endl;
    cout << a[1] << endl;
    cout << a[2] << endl;
    
    
    
    // for each loop
    for(int i : vec){
        cout << i << endl;
    }


    // size
    cout << "size of vec = "<< vec.size() << endl << "Now add elements" << endl;

    // insert a number in vector
    vec.push_back(56);
    vec.push_back(35);
    vec.push_back(27);
    vec.push_back(8);

    cout<<"vector after update "<< endl;

    for(int i : vec){
        cout << i << endl;
    }

    cout<<"size after push back = "<< vec.size()<<endl;


    cout<<"now delition "<<endl;

    // delete a number from vector
    vec.pop_back();

    cout<<"vector after update "<< endl;

    for(int i : vec){
        cout << i << endl;
    }

    cout<<"size after pop back = "<< vec.size()<<endl;

    // front value

    cout<<"value in front = "<< vec.front()<<endl;

    // value at back

    cout<< "value at back = " << vec.back()<<endl;

    // value at any index

    cout<<"value at 3rd index = "<<vec.at(3)<<endl;
    
    // simillar to -- 

    cout << vec[3];

    // capacity vs size of vector
    
    cout <<"capacity vs size "<< endl << "size = "<< vec.size()<<endl<<"capacity = "<<vec.capacity()<<endl;



    return 0;
}