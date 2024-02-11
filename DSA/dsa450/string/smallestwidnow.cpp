#include <bits/stdc++.h>
using namespace std;
vector<int> save(125,0);
vector<int> arr(125, -1);
int check()
{
    int ans = 0;
    for (int i = 0; i < 125; i++)
    {
        if (arr[i] != -1 )
        {   if( arr[i]<save[i])
            {ans += save[i]-arr[i];}
        }
    }
    return ans;
}
string smallestWindow(string s, string x)
{
    if (x.length() < 2)
    {
        return x;
    }
    for (auto i : x)
    {
        save[(int)i]++;
        arr[(int)i]=0;
    }
    int l = 0, r = 0;
    int start = 0, end = x.length();
    while (r < s.length())
    {
        while (start < end)
        {

            if (arr[(int)s[r]] != -1)
            {
                arr[(int)s[r]]++;
            }
            r++;
            start++;
        }
        int temp = check();
        if (temp != 0)
        {
            end += temp;
        }
        else
        {
            break;
        }
    }
    int distance = r - l, pos = l;
    if (distance == x.length())
        return s.substr(pos, distance);
    while (true)
    {   int arrele = arr[(int)s[l]];
        int saveele = save[(int)s[l]];
        char elel = s[l];
        char eler = s[r];
        if (arr[(int)s[l]] <= save[(int)s[l]] && r<s.length() && arr[(int)s[l]]!=-1)
        {
            if(arr[(int)s[r]]!=-1)
            {arr[(int)s[r]]++;}
            
            r++;
            if(arr[(int)s[l]] == save[(int)s[l]])
            {
               if ((r - l) < distance)
                {
                distance = r - l;
                pos = l;
                } 
            }
        }
        else if(r==s.length() && arr[(int)s[l]]==save[(int)s[l]])
        {
            break;
        }
        else 
        {
            arr[(int)s[l]]--;
            l++;
            if ((r - l) < distance)
            {
                distance = r - l;
                pos = l;
            }
        }
    }
    return s.substr(pos, distance);
}
int main()
{ /*ilovecodingninjas
oiln*/
    string s = "codingninjas";
    string x = "inn";
    cout << smallestWindow(s, x);
}