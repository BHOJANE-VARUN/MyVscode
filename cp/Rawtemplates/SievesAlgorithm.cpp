#include<iostream>
#include<vector>
using namespace std;
// const int siz = 5*(1e5);
// vector<bool> arr(siz,1);
// vector<int> prime;
//It is a prime generator upto 5 * 1e6 th prime(and trust me it is huge) 
// void buildsieve()
// {   
//     for(int i =2;i<siz;i++)
//     {
//         arr[i] =true;
//     }
//     arr[0] = false;
//     for(int i =2;i<siz;i++)
//     {
//         if(arr[i]==true)
//         {
//             for(int j = i*i;j<siz;j+=i)
//             {
//                 arr[j] = false;
//             }
//            // prime.push_back(i);
//         }

//     }
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
// }
// second approch, upper is not working
//Damn, this works for 1e7 
const int N = 1e7 +10;
vector<bool> isPrime(N,1);
void building(int value)
{
    isPrime[0] = false;
    for(int i = 2;i*i<value;i++)
    {
        if(isPrime[i])
        {
            for(int j = i*2;j<value;j+= i)
            {
                isPrime[j] = false;
            }
        }
    }
}
int main()
{
    building(1e5);
    int ct =0;
    for(int i =0;i<N;i++)
    {
        if(isPrime[i]) ct++;
    }
    cout<<ct<<endl;
}