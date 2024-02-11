#include <bits/stdc++.h>
using namespace std;
string ninjaAndStringConversion(int n, string &s){
	for(int i =0;i<n;i++)
	{
		if(65<=(int)s[i] && (int)s[i]<=90)
		{	if(s[i]!='A')
			{s[i] = (char)((int)s[i]-1);}
			else {s[i]='Z';}
		}
		else{
			if(s[i]!='z')
			s[i] = (char)((int)s[i]+1);
			else s[i]='a';
		}
	}
	return s;
	
}
int main()
{
    string s = "Abz";
    cout<<ninjaAndStringConversion(s.length(),s);

}