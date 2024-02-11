#include <iostream>
using namespace std;

// #include<bits/stdc++.h>
// using namespace std;
// void inputarrInt(int *arr,int n)
// {   int temp;
//     for(int i =0;i<n;i++)
//     {
//         cin>>temp;
//         arr[i] = temp;
//     }
// }
int main()
{
int t;
cin>>t;
while (t--)
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    int f =-1;
    for(int i =0;i<n-2;i++)
    {
        if(str[i]-'0')
        {
            f =i;
            break;
        }
        
    }
    string ans(n,'0');
    if(f!=-1)
    {ans[f] = '1';
    cout<<ans<<endl;}
    else{
        cout<<str<<endl;
    }
}

}