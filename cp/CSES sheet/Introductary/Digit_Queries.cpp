#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
signed main()
{

int ele = 10;
int ct =8;
int num = 2;
int count =8;
map<int,pair<int,int>> mp;
vector<int> mods;
mp[count] = {ele,num};
for(int i =0;i<16;i++)
{
    mods.push_back(count);
    ct = ct*10 +9;
    ele = ele*10;
    num++;
    count = count + ct*num;
    mp[count]={ele,num};
    
}
test{
    int num;
    cin>>num;
    if(num<10)
    {
        cout<<num<<endl;
        continue;
    }
    int index = mods.size()-1;
    while(index>=0)
    {
        if(num%mods[index]==num)
        {
            index--;
        }
        else{
            break;
        }
    }
    int start = mp[mods[index]].first-1;
    int digits = mp[mods[index]].second;
    //cout<<start<<" "<<digits<<endl;
    num = num - mods[index];
    while(num-digits>=0)
    {

        start++;
        num = num-digits;   
    }
    string str = to_string(start);
    cout<<str[num]<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}