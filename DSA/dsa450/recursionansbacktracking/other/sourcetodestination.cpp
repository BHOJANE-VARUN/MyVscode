#include<iostream>
using namespace std;
bool solve(int s1,int s2,int e1,int e2)
{
    if(s1>e1 || s2>e2)return false;
    if(s1==e1 && s2==e2)return true;

    if(solve(s1+s2,s2,e1,e2))return true;
    if(solve(s1,s1+s2,e1,e2))return true;

}
int main()
{
    int s1 = 1,s2=1,e1=1,e2=4;
    cout<<solve(s1,s2,e1,e2);
}