#include <iostream>
using namespace std;

int main() {
	// your code goes here
	// int test;
	// cin>>test;
	// while(test)
	// {
	    float x=80;
	    
	    float co = (20*x)/100;
	    float ans = 100/co;
	    if(ans!=int(ans))
	    {ans = int(ans);
	    ans++;
	    cout<<ans<<endl;}
	    else{
	        ans = int(ans);
	        cout<<ans<<endl;
	    }
	    //test--;
	// }
	return 0;
}