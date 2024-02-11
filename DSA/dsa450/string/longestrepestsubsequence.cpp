#include <bits/stdc++.h>
#define lop(s,e) for(int i=s;i<e;i++)
#define whi(e) while(i<e)
#define l(str) str.length()
using namespace std;
int LRS(string & str) {
    int len = l(str);
    int ans =0;
    for (int i = 0; i <len-1 ; i++)
    {
        int ind = str.find(str[i],i+1);
        if (ind<len)
        {   int count = 1;
            int pre = i+1;
            ind++;
            while(len>ind)
            {
                if(str[ind]==str[pre])
                {
                    count++;
                    ind++,pre++;
                }
                else
                {
                    ind++;
                }
                
            }
        }
            

        }
        
    }
    
    
}