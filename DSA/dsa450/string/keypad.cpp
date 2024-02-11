#include <bits/stdc++.h> 
using namespace std;
string covertSentence(string str, int size){
	string ans;
	for(int i =0;i<size;i++)
	{
		switch(str[i])
		{
			case 'a':ans+=("2");break;
			case 'b':ans+=("22");break;
			case 'c':ans+=("222");break;
			case 'd':ans+=("3");break;
			case 'e':ans+=("33");break;
			case 'f':ans+=("333");break;
			case 'g':ans+=("4");break;
			case 'h':ans+=("44");break;
			case 'i':ans+=("444");break;
			case 'j':ans+=("5");break;
			case 'k':ans+=("55");break;
			case 'l':ans+=("555");break;
			case 'm':ans+=("6");break;
			case 'n':ans+=("66");break;
			case 'o':ans+=("666");break;
			case 'p':ans+=("7");break;
			case 'q':ans+=("77");break;
			case 'r':ans+=("777");break;
			case 's':ans+=("7777");break;
			case 't':ans+=("8");break;
			case 'u':ans+=("88");break;
			case 'v':ans+=("888");break;
			case 'w':ans+=("9");break;
			case 'x':ans+=("99");break;
			case 'y':ans+=("999");break;
			case 'z':ans+=("9999");break;
		
		}
	}
	return ans;
}
int main()
{
    string test = "abc";
    string str = covertSentence(test,3);
    cout<<str;
}