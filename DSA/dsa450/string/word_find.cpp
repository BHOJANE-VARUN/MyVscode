#include <bits/stdc++.h> 
using namespace std;
vector<pair<char, int>> mapit(string str) {
    int n = str.length();
    vector<pair<char, int>> ans(n);
    int len = 0; // Length of the longest proper prefix that is also a suffix

    ans[0] = make_pair(str[0], -1);

    for (int i = 1; i < n; i++) {
        while (len > 0 && str[i] != str[len])
            len = ans[len - 1].second + 1;

        if (str[i] == str[len]) {
            len++;
        } else {
            len = 0;
        }

        ans[i] = make_pair(str[i], len - 1);
    }

    return ans;
}

int checkpattern(string pattern,string main)
{
    vector<pair<char,int>> pi_table =mapit(pattern);
    int j =0;
    int ind = -1;
    int ans =0;
    while(j<main.length())
    {
        if(main[j]==pattern[ind+1])
        {
            j++,ind++;
            if(ind+1==pattern.length())
            {
            ans++;
            ind = pi_table[ind].second;
            }
        }
        else{

            if(ind!=-1)ind = pi_table[ind].second;
            else{j++;}
            
        }
        
        
    }
    return ans;
}
int findstring(string word,string str)
{   int ans =0;
    int i =0;
    ans += checkpattern(word,str);
    reverse(word.begin(),word.end());
    ans += checkpattern(word,str);
    
    return ans;
}
int wordSearch(string grid[], int n, int m, string word) {
    int ans = 0;
    for(int i =0;i<n;i++)
    {
        ans+= findstring(word,grid[i]);
    }
    for(int j =0;j<m;j++)
    {   string temp;
        for(int k =0;k<n;k++)
        {
            temp.push_back(grid[k][j]);
        }
        ans+= findstring(word,temp);
    }
    int j=0;
    while((n-j)>=word.length())
    {   int row=0,col=j;
        string temp;
        while(row<n && col<m)
        {
            temp.push_back(grid[row][col]);
            row++,col++;
        }
        ans+= findstring(word,temp);
        j++;
    }
    

    int i =1;
    while((n-i)>=word.length())
    {
        int col =0,row =i;
        string temp;
        while (row<n && col<m)
        {
            temp.push_back(grid[row][col]);
            row++,col++;
        }
        ans +=findstring(word,temp);
        i++;
    }
    i =1;
    while(i<n)
    {
        int col =m-1,row =i;
        string temp;
        while (row<n && col>-1)
        {
            temp.push_back(grid[row][col]);
            row++,col--;
        }
        ans +=findstring(word,temp);
        i++;
    }
     
     j=m-1;
    while(j>0)
    {   int row=0,col=j;
        string temp;
        while(row<n && col>-1)
        {
            temp.push_back(grid[row][col]);
            row++,col--;
        }
        ans+= findstring(word,temp);
        j--;
    }
    
    return ans;
}
int main()
{   /*AANIQ
RIAN
IAIR
AIRI
IAIR
AIRI
NINJA*/
    string grid[]={"XXXX","XXXX","XXXX","XXXX","XXXX"};
    string word = "XX";
    int n =5,m=4;
    int ans = wordSearch(grid,n,m,word);
    cout<<ans;
}