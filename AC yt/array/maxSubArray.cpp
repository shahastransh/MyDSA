#include <iostream>
using namespace std;


int main(){
    int n =5;
    int arr[n] = {6,7,5,8,9};
    for(int st=0; st < n; st++ ){
        for(int end=st; end < n; end++){
            for(int i = st; i <=end ; i++){
                cout << arr[i] ;
            }
            cout<<" ";
        }
        cout<<endl;
    }

    return 0;

}