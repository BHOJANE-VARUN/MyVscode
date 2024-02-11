#include <iostream>
#include<string>
using namespace std;

int main() {
	// your code goes here
    int test;
    cin>>test;
    while (test)
    {   string str;
        cin>>str;
        int count = str.length();
        int ans=1;
        for (int i = 2; i < count; i++)
        {
            if(str[i]=='0')
            {
                int sum = str[i-1]+str[i-2];
                if(sum)
                {
                    
                }
            }
        }
        test--;
    }
    
	return 0;
}