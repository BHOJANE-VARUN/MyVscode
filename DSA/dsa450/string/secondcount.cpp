#include <bits/stdc++.h> 
using namespace std;
string second_repeat(vector<string> &arr, int n){
    unordered_map<string,int> map;
    for(auto i:arr)
    {
        map[i]++;
    }
    string strmax,strmax2;
    int numax=0,num2=0;
    for(auto i:map)
    {
        if(num2<i.second){
            num2=i.second;
            strmax2=i.first;
        }
        if(numax<num2)
        {
            swap(num2,numax);
            swap(strmax2,strmax);
        }
    }
    return strmax2;
}
int main()
{
    vector<string> test = {"aaa","bbb","aaa"};
    string str = second_repeat(test,3);
    cout<<str; 
}