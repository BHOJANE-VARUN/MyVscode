#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    if(n>=5)
	    {
	        cout<<1<<" "<<n-1<<endl;
	    }
	    else{
	        cout<<0<<" "<<n<<endl;
	    }
	}
	return 0;
}