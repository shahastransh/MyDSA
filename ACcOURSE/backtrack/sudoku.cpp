#include<bits/stdc++.h>
using namespace std;

void print_sudoku(int sudoku[][9]){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout<< sudoku[i][j] << " ";
        }
        cout << endl;
    }
}


bool isSafe(int sudoku[9][9], int row, int col, int digit){
    // vertical
    for(int i = 0; i< 8; i++){
        if(sudoku[i][col] == digit){
            return false;
        }
    }

    // ?horizontal
    for(int j = 0; j < 8 ; j++){
        if(sudoku[row][col] == digit){
            return false;
        }
    }

    // 3*3 box
    int sC = (col/3) * 3;
    int sR = (row/3) * 3;

    for(int i = sR; i < sR+2; i++){
        for(int j = sC; j< sC +2; j++){
                if(sudoku[i][j] == digit){
                return false;
            }

        }
    }
    return true;

}

bool sudoku_solver(int sudoku[9][9], int row, int col){
     if(row == 9){
        print_sudoku(sudoku);
        return true;
     }

    int nextRow = row ;
    int nextCol = col + 1;
    if( col + 1 == 9){
        nextRow = row+1;
        nextCol = 0;

    }

    if(sudoku[row][col] != 0){
        return sudoku_solver(sudoku, nextRow, nextCol);
    }


    for(int digit = 1; digit <= 9; digit++){
        if(isSafe(sudoku, row, col, digit)){
            sudoku[row][col] = digit;
            if(sudoku_solver(sudoku, nextRow, nextCol)){
                return true;
            }
            sudoku[row][col] = 0;
        }
    }

    return false;
}




int main() {
    int sudoku[9][9] = {{0, 0, 8, 0, 0, 0, 0, 0, 0},
                        {4, 9, 0, 1, 5, 7, 0, 0, 2},
                        {0, 0, 3, 0, 0, 4, 1, 9, 0},
                        {1, 8, 5, 0, 6, 0, 0, 2, 0},
                        {0, 0, 0, 0, 2, 0, 0, 6, 0},
                        {9, 6, 0, 4, 0, 5, 3, 0, 0},
                        {0, 3, 0, 0, 7, 2, 0, 0, 4},
                        {0, 4, 9, 0, 3, 0, 0, 5, 7},
                        {8, 2, 7, 0, 0, 9, 0, 1, 3}};

    sudoku_solver(sudoku,0,0);

    return 0;
}