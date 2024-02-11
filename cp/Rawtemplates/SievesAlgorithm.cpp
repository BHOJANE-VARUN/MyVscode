#include<iostream>
#include<vector>
using namespace std;
bool arr[86028122];
vector<int> prime;
//It is a prime generator upto 5 * 1e6 th prime(and trust me it is huge) 
void buildsieve()
{   
    for(int i =2;i<=86028121;i++)
    {
        arr[i] =true;
    }
    arr[0] = false;
    for(int i =2;i*i<=86028121;i++)
    {
        if(arr[i]==true)
        {
            for(int j = i*i;j<=86028121;j+=i)
            {
                arr[j] = false;
            }
            prime.push_back(i);
        }

    }
    // int limit = 5 * 1e6;
    // int ct =0;
    // int size =0;
    // for(int i = 2;;i++)
    // {//86028121
    //     if(arr[i]==true)
    //     {
    //         ct++;
    //     }
    //     if(ct==limit)
    //     {
    //         size = i;
    //         break;
    //     }
    // }
    // cout<<size<<endl;
}
int main()
{
    buildsieve();
    for(int i =0;i<10;i++)
    {
        cout<<prime[i]<<" "; 
    }
}