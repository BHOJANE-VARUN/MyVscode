#include <iostream>
using namespace std;

// int main() {
// 	int t=1;
// 	//cin>>t;
// 	while(t--)
// 	{
// 	    int n,k;
//         n = 4,k = 3;
//         int arr[] = {2, 6 ,7 ,4};
//         //for(int i =0;i<n;i++) cin>>arr[i];
//         //int *wid = new int[k];
//         int ans =0;
//         int odd =0;
//         for(int i =0;i<k;i++)
//         {   
//             if(arr[i]%2) odd++;
//         }
//         for (int i = k; i < n; i++)
//         {
//             if(odd>0) ans++;
//             if(arr[i-k]%2) odd--;
//             if(arr[i]%2) odd++;
//         }
//         if(odd>0)   ans++;
//         cout<<ans<<endl;
// 	}
// 	return 0;
// }
int main() {
	// your code goes here
	int t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int ans = 1;
	    while(n>0)
	    {
	        ans *= n;
	        n--;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
