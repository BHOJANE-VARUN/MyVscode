#include <iostream>
#include<string>
using namespace std;

int main() {
	// your code goes here
	int t;
    cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        int ans = 0;
        for(int i =0;i<n;i++)
        {
            char my = a[i];
            char your = b[i];
            if(my==your)
            {
                continue;
            }
            else if((my=='R' and your=='S') or (my=='P' and your=='R') or (my=='S' and your=='P'))
            {
                ans++;
            }
            else{
                ans--;
            }
        }
        if(ans<0)
        cout<<abs(ans)<<endl;
        else if(ans==0) cout<<1<<endl;
        else cout<<0<<endl;
    }
	return 0;
}