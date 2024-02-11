int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    for(int j=0;j<m;j++)
    {
    for(int i=0;i<n;i++)
    {
      if (matrix[i][j]==1) {
          return i;
      };
    }
    }
    return -1; 
}