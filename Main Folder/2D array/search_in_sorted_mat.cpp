#include<iostream>
using namespace std;

bool search_in_sorted_mat(int mat[][4], int n, int m, int key){
    int i = 0, j = m-1;

    while(i < n && j >= 0){
        if(mat[i][j] == key){
            cout << "found at " << i << "," << j << endl;
            return true;
        }else if(mat[i][j] < key){
            i++;
        }else{
            j--;
        }
    }

    cout << " key not found " << endl;
    return false;
}

int main(){
    int mat[4][4] ={{10,20,30,40},
                    {15,15,35,45},
                    {27,29,37,48},
                    {32,33,39,50}};

    search_in_sorted_mat(mat, 4,4,100);


    return 0;
}