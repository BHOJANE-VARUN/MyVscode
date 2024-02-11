#include<iostream>
#include<stack>
#include<vector>
using namespace std;
bool validStackPermutation(vector<int> &first, vector<int> &other){
	stack<int> sk;
    for(int i=0,j=0;i<first.size();i++)
    {   int ele = first[i];
        sk.push(first[i]);
        int e = other[j];
        while((!sk.empty()) && sk.top()==other[j])
        {
            sk.pop();
            j++;
        }
    }
    return sk.empty();
}
int main()
{
    vector<int> vec = {2,4,6};
    vector<int> other = {6,2,4};
    cout<<validStackPermutation(vec,other);
}