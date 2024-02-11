#include <bits/stdc++.h> 
using namespace std;
// int maxStackSum(vector<int> &stack1, vector<int> &stack2, vector<int> &stack3) 
// {
//     // Write your code here.
//     int ans =0;
//     int sum1 =0,sum2=0,sum3=0,i=stack1.size()-1,j=stack2.size()-1,k=stack3.size()-1;
//     while(i>=0 && j>=0 && k>=0)
//     {   if(sum1<=sum2 && sum1<=sum3)
//         {int ele = stack1[i];
//         stack1[i] += sum1;
//         sum1 += ele;
//         i--;}
//         else if(sum2<=sum3 && sum2<=sum1)
//         {int ele = stack2[j];
//         stack2[j] += sum2;
//         sum2 += ele;
//         j--;}
//         else
//         {int ele = stack3[k];
//         stack3[k] += sum3;
//         sum3 += ele;
//         k--;}

//         if(sum1==sum2 && sum2==sum3)
//         {
//             ans = max(ans,sum1);
//         }
//     } 
//     if(sum1==sum2 && sum2==sum3)
//         {
//             ans = max(ans,sum1);
//         }
//     return ans;
// }
int maxStackSum(vector<int> &stack1, vector<int> &stack2, vector<int> &stack3) 
{

    // Write your code here.
    int sum =0;
    for(int i =stack1.size()-1;i>=0;i--)
    {   int ele = stack1[i];
        stack1[i] += sum;
        sum += ele;
    }
    sum =0;
    for(int i =stack2.size()-1;i>=0;i--)
    {   int ele = stack2[i];
        stack2[i] += sum;
        sum += ele;
    }
    sum =0;
    for(int i =stack3.size()-1;i>=0;i--)
    {   int ele = stack3[i];
        stack3[i] += sum;
        sum += ele;
    }
    int i =0,j = 0,k = 0;
    int ans =INT_MIN;
    while(i<stack1.size() && j<stack2.size() && k<stack3.size())
    {   if(stack1[i]==stack2[j] && stack2[j]==stack3[k])
        {
            ans = max(ans,stack1[i]);
            i++,j++,k++;
        }
        else if(stack1[i]>=stack2[j] && stack1[i]>=stack3[k])
        {
            i++;
        }
        else if(stack2[j]>=stack1[i] && stack2[j]>=stack3[k])
        {
            j++;
        }
        else{
            k++;
        }
    }
    return ans;
}
   

int main()
{
    vector<int> one = {4 ,5 ,2 ,3};
    vector<int> secon = {3 ,1 ,4};
    vector<int> thri = {2 ,2 ,1};
    cout<<maxStackSum(one,secon,thri);
}