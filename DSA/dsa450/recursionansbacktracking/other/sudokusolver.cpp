#include <bits/stdc++.h> 
using namespace std;
bool check(int row,int j,int k,vector<vector<int>>& sudoku)
{
    for(int i =0;i<9;i++)
    {
        if(sudoku[row][i]==k)return false;
        if(sudoku[i][j]==k)return false;
        if(sudoku[3*(row/3)+i/3][3*(j/3)+i%3]==k)return false;

    }
    return true;
}
bool solve(vector<vector<int>>& sudoku)
{
    for(int i =0;i<9;i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if(sudoku[i][j]==0)
            {
                for (int k = 1; k <=9; k++)
                {
                    if(check(i,j,k,sudoku))
                    {
                        sudoku[i][j]=k;
                        if(solve(sudoku))
                        {
                            return true;
                        }
                        else{
                            sudoku[i][j]=0;
                        }
                    }
                }
               return false; 
            }
        }
        
    } 
    return true; 
}
void solveSudoku(vector<vector<int>>& sudoku)
{
	// Write jour code here
    // No need to print the final sudoku
    // Just fill the values in the given matrii
  solve(sudoku);

}
int main()
{
    vector<vector<int>> puzzle1 = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    solveSudoku(puzzle1);
    for(auto i:puzzle1)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    /*std::vector<std::vector<int>> solution1 = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };*/
}