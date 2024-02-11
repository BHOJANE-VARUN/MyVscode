#include<bits/stdc++.h>
using namespace std;
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
    for(int i =0;i<n-2;i++)
    {
        if(str[i]-'0')
        {
            str[i+1] = '0';
            str[i+2] = '0';
        }
    }
    cout<<str<<endl;
}

}