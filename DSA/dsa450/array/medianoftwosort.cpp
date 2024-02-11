#include <bits/stdc++.h>
using namespace std;
double median(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();
    int total = (n+m)/2;
    int i =((total+1)/2)-1,j = (total/2)-1;
    while(i>-1 && j>-1)
    {
        if(a[i]>b[j+1])
        {
            i--;j++;
        }
        else if (b[j]>a[i+1])
        {
                j--,i++;
        }
        else{
            break;
        }
        
    }
    if((n+m)%2==0){
   int mx = max(a[i],b[j]);
   int mi = min(a[i+1],b[j+1]);
   return (mx+mi)/2.0; 
    }
    else{
       return min(a[i+1],b[j+1]); 
    }

}
int main(){
// 2 4 6
// 1 3
vector<int> te = {2,4,6};
vector<int> ta = {1,3};
double ans = median(te,ta);
cout<<ans;
}