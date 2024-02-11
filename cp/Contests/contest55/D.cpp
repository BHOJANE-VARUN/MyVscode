#include<bits/stdc++.h>
typedef long long int ll;
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//ll arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
// void inputarrll(ll *arr,ll n)
// {   ll temp;
//     for(ll i =0;i<n;i++)
//     {
//         cin>>temp;
//         arr[i] = temp;
//     }
// }
bool solve(int x,int y,int z)
{

}
int main()
{
test
{
    int x,secele;cin>>x>>secele;
    int low = -1000,high = secele-1;
    int ct = (3*x)-secele;
    int mid;
    while (low<high)
    {
        int ele = ct-low;
        if((x==(ele+secele+low)/3) and ele<=1000)
        {
            cout<<low<<" "<<secele<<" "<<ele<<endl;
            break;
        }
        low++;
    }
    
}
//dusro ka code copy karne se khar nahi chalta bhai
}