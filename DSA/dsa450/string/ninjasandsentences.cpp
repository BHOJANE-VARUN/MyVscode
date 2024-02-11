#include <bits/stdc++.h>
using namespace std;
void createSentences(vector<vector<string>> &arr, vector<vector<string>> &ans)
{   vector<vector<string>> temppri;
    vector<string> emp = {};
    temppri.push_back(emp);
    for (int i = 0; i < arr.size(); i++)
    {
        int size = temppri.size();
        for (auto ansele : temppri)
        {  
            for (int j = 0; j < arr[i].size(); j++)
            {   vector<string> tempvec=ansele;
                tempvec.push_back(arr[i][j]);

            }
        }
    }
}