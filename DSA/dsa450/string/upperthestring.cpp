#include <bits/stdc++.h>
using namespace std;
char upper(char str)
{	
	int dif = str-'a';
	return	dif+'A';
}
 
string convertString(string str) 
{	str[0]=upper(str[0]);
	for(int i=1;i<str.length();i++)
	{
		if(str[i]!=' ')
		{
			continue;
		}
		else{
			str[i+1]=upper(str[i+1]);
		}
	}
	return str;
}
int main()
{
    string str = "I am second year";
    str = convertString(str);
    cout<<str;
}