#include "unordered_map"
#include<iostream>
#include<vector>
using namespace std;
char kThCharaterOfDecryptedString(string s, long long k){

    // Write your code here.

    int i,j;

    long long lenss;

    long long freq;

    long long len;

    i = 0;

    int n = s.size();

    while(i<n){

        j = i;

        lenss = 0;

        while(j<n && isalpha(s[j])){

            j++;

            lenss++;

        }

        freq = 0;

        while(j<n && isdigit(s[j])){

            freq = freq*10 + s[j]-'0';

            j++;

        }

        len = (long long)lenss*(long long)freq;

 

        if(k>len){

            k = k - len;

            i = j;

        }

        else{

            k--;

            k = k%lenss;

            return s[i+k];

        }

    }

    return s[k-1];

}
int main()
{
    cout<<kThCharaterOfDecryptedString("ab12c3",20);
}