#include<bits/stdc++.h>
using namespace std;

// 1 1 1         1 0 1
// 1 0 1   -->   0 0 0
// 1 1 1         1 0 1

void setMatrixZeros_approach_1(vector<vector<int>> &matrix, int row, int col);
void setMatrixZeros_approach_2(vector<vector<int>> &matrix, int row, int col);

int main(){
    int row = 3, col = 3;
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    // Calling Function (Approaches)
    setMatrixZeros_approach_1(matrix, row, col);
    setMatrixZeros_approach_2(matrix, row, col);


    // Output
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            cout << matrix[r][c];
        }
        cout<<endl;
    }
}


//! Brute Force Approach
void setMatrixZeros_approach_1(vector<vector<int>> &matrix, int row, int col){
    // Creating dummy array for row & col;
    vector<int> rowIndex(row, 1), colIndex(col, 1);

    // Traversing through array and storing the position of zeros w.r.t row & col
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            if(matrix[r][c] == 0){
                rowIndex[r] = 0;
                colIndex[c] = 0; 
            }
        }
    }

    // Filling the array with zeros
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            if(rowIndex[r] == 0 || colIndex[c] == 0)
                matrix[r][c] = 0;
        }
    }
}



//! Optimal Approach
void setMatrixZeros_approach_2(vector<vector<int>> &matrix, int row, int col){
    int col0 = 1;

    // Instead of creating dummy array, we take in previous approach
    // Include first row and first col of matrix as dummy array
    // Since matrix[0][0] is intersecting that's why col0 taken

    // If we found 0, this will change respective row and col to 0
    for(int r = 0; r < row; r++){
        if(matrix[r][0] == 0) col0 = 0;
        for(int c = 1; c < col; c++){
            if(matrix[r][c] == 0){
                matrix[r][0] = 0;
                matrix[0][c] = 0;
            }
        }
    }

    // Setting 0, if we found respective first row and first col = 0
    for(int r = row-1; r >= 0; r--){
        for(int c = col-1; c>=0; c--){
            if(matrix[r][0] == 0 || matrix[0][c] == 0)
                matrix[r][c] = 0;
        }
        if(col0 == 0)
            matrix[r][0] = 0;
    }
}