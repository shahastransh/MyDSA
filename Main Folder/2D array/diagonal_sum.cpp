#include<iostream>
using namespace std;


// int diagonal_matrix( int mat[][3],int n){
//     int sum = 0;
//     for(int i = 0; i<n; i++){
//         for(int j = 0; j < n; j++ ){
//             if(i == j){
//                 sum += mat[i][j];
//             }else if(j == n-i-1){
//                 sum += mat[i][j];
//             }
//         }
//     }
    
//     cout << "sum = " << sum << endl;
// }

int optimized_diagonal_matrix( int mat[][3],int n){
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += mat[i][i]; //pd
        if( i != n-i-1){
            sum += mat[i][n-i-1]; //sd
        }
            
        
    
    }
    cout << "sum = " << sum << endl;
}
int main(){
    int n = 4;
    int m = 3;
    // int matrix[n][n] = {{1,2,3,4},
    //                     {5,6,7,8},
    //                     {9,10,11,12},
    //                     {13,14,15,16}};

    int matrix2[3][3] = {{1,2,3},
                        {4,5,6},
                        {7,8,9},
                        };

    // diagonal_matrix(matrix, 4);
    // diagonal_matrix(matrix2, 3);
    optimized_diagonal_matrix(matrix2, 3);
    return 0;
}

