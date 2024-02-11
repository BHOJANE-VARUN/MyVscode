#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t!=0){
	    t--;
	    int n,k;
	    cin>>n>>k;
	    int c=0;
	    int f=0;
	    while(n%k!=0){
	       n++;
	       k--;
	   if(n%k==0){
	       c++;
	       cout<<c<<endl;
	       f=1;
	       break;
	   }
	  else{
	      c++;
	  }
	    }
	    if(f==0) cout<<0<<endl;
	    
	}
	
	return 0;
}