#include <bits/stdc++.h> 
using namespace std;
// bool unordered_mapvalue(vector<int> arr)
// {
//     for(int i =0;i<125;i++)
//     {
//         if(arr[i]>0)
//         {   
//             return false;
//         }
//     }
//     return true;
// }
// string shortestSubstring(string s)
// {  vector<int> arr(125,0);
//    vector<pair<int,int>> sizpos;
//    for(auto i:s)
//    {
//         arr[(int)i]=1;
//    }
//    int r=0;
//    vector<int> temp(125,0);
//    temp = arr;
//    temp[(int)s[r]]--;
// for(int i =0;i<s.length();i++)
//    {while(r<s.length()-1)
//    {    
//         if(unordered_mapvalue(temp))
//         {
//             pair<int,int> tempair = make_pair(r-i+1,i);
//             sizpos.push_back(tempair);
//             temp = arr;
//             r=i;
//             temp[(int)s[r]]--;
//             break;
//         }
//         else{
//             r++;
//             temp[(int)s[r]]--;
//         }
//    }
//    if(unordered_mapvalue(temp))
//         {
//             pair<int,int> tempair = make_pair(r-i+1,i);
//             sizpos.push_back(tempair);
//             temp = arr;
//             i++;r=i;
//             temp[(int)s[i]]--;
//             continue;
            
//         }}
//     sort(sizpos.begin(),sizpos.end());
//     for(auto i:sizpos)
//     {
//         cout<<i.first<<"  "<<i.second<<"\n";
//     }
//     return s.substr(sizpos[0].second,sizpos[0].first);

// }
bool check(unordered_map<char,int> arg)
{
    for(auto i:arg)
    {
        if(i.second==0)
        {
            return  false;
        }
    }
    return true;
}
bool canremove(int l,unordered_map<char,int> arg,string s)
{
    if(arg[s[l]]>1)
    {
        return true;
    }
    else{
        return false;
    }
}
string shortestSubstring(string s)
{   unordered_map<char,int> unordered_map;
    for(auto i:s)
    {
        unordered_map[i]=0;
    }
    int size = unordered_map.size();
    int distance =INT_MAX;
    int start =0;
    int l =0,r=0;
    unordered_map[s[r]]++;
    int flag =0;
    while (flag!=1)
    {   bool bol = check(unordered_map);
        if(r<s.length() && bol!=true)
        {
            r++;
            unordered_map[s[r]]++;

        }
        else if(bol && canremove(l,unordered_map,s))
        {
            unordered_map[s[l]]--;
            l++;
            if(distance>(r-l+1))
            {
                distance = r-l+1;
                start = l;
                if(distance==size)
                {
                    break;
                }
            }
        }
        else if(r<s.length())
        {   if(distance>(r-l+1))
            {
                distance = r-l+1;
                start = l;
                if(distance==size)
                {
                    break;
                }
            }
            unordered_map[s[l]]--;
            l++;
            r++;
            unordered_map[s[r]]++;

        }
        else{
            flag =1;
        }
    }
   return s.substr(start,distance); 

}
/*MOST OPTIMAL CODE 
#include <bits/stdc++.h> 
#include <bits/stdc++.h> 

const int MAX_CHARS = 256;

string shortestSubstring(string str)

{

    int n = str.length();

    if (n <= 1)

        return str;

    int dist_count = 0;

    bool visited[MAX_CHARS] = { false };

    for (int i = 0; i < n; i++) {

        if (visited[str[i]] == false) {

            visited[str[i]] = true;

            dist_count++;

        }

    }

    int start = 0, start_index = -1, min_len = INT_MAX;

    int count = 0;

    int curr_count[MAX_CHARS] = { 0 };

    for (int j = 0; j < n; j++) {

        curr_count[str[j]]++;

        if (curr_count[str[j]] == 1)

            count++;

        if (count == dist_count) {

            while (curr_count[str[start]] > 1) {

                if (curr_count[str[start]] > 1)

                    curr_count[str[start]]--;

                start++;

            }

            int len_window = j - start + 1;

            if (min_len > len_window) {

                min_len = len_window;

                start_index = start;

            }

        }

    }

    return str.substr(start_index, min_len);

}*/
int main()
{
    string test = "abbcabc";
    cout<<shortestSubstring(test);
}