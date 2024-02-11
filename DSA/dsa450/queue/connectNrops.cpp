#include<iostream>
#include<queue>
using namespace std;
long long connectRopes(int* arr, int n)
{
    // Your code goes here
      long long int ans=0;
    priority_queue<int, vector<int>, greater<int>>pq;
    if(n==1) return ans;
    for(int i =0;i<n;i++)
    {
        pq.push(arr[i]);
    }
    while(pq.size()!=1)
    {
        int ele = pq.top();
        pq.pop();
        int ele2 = pq.top();
        pq.pop();
        int sum = ele + ele2;
        pq.push(sum);
        ans += sum;
    }
    return ans;
}
int main()
{
    return 0;
}