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

bool arr[1000000+1];
void buildsieve()
{   
    for(int i =2;i<1000000+1;i++)
    {
        arr[i] =true;
    }
    arr[0] = false;
    arr[1] = false;
    for(int i =2;i*i<1000000+1;i++)
    {
        if(arr[i]==true)
        {
            for(int j = i*i;j<1000000+1;j+=i)
            {
                arr[j] = false;
            }
           // prime.push_back(i);
        }

    }
    
}
int main()
{
buildsieve();  
int t;
cin>>t;
while (t--)
{   
    int cur = 1;
    int n;
    cin>>n;
    int ct =0;
    while (arr[n]!=true and n>0)
    {
        n -= cur;
        cur = cur *2;
        ct++;
    }
    if(n>=0)
    cout<<ct+1<<endl;
    else cout<<-1<<endl;
}

}