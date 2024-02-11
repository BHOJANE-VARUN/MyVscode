#include <bits/stdc++.h>
using namespace std;
int miniNumSwaps(string brackets, int n)
{
    int op=0,cl=0,unbal=0,swaps =0;
    for(int i=0;i<brackets.length();i++)
    {
        if(brackets[i]==40)
        {
            if(unbal!=0)
            {
                swaps +=unbal;
                unbal--;
                
            }
            else{
                op++;
            }
        }
        else{
            if(op>cl)
            {
                cl++;
            }
            else{
                unbal++;
            }
        }
    }
    return swaps;
}
int main()
{
    string test = "))((";
    int n = test.length();
    cout << miniNumSwaps(test, n);
    return 0;
}