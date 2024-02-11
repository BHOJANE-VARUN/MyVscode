#include <bits/stdc++.h> 
using namespace std;
bool areIsomorphic(string &str1, string &str2)
{
    if(str1.length()!=str2.length())
    {
        return false;
    }

    unordered_map<char,int> map1;
    unordered_map<char,int> map2;
    for(int i =0;i<str1.length();i++)
    {
        map1[str1[i]]++;
        map2[str2[i]]++; 
    }
    auto it1 = map1.begin();
    auto it2 = map2.begin();
    while(it1!=map1.end())
    {   
        if((*it1).second!=(*it2).second)
        {
            return false;
        }
        it1++,it2++;
    }
    return true;
}
/*bool areIsomorphic(string &str1, string &str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    unordered_map<char, char> charMap1; // Mapping from str1 to str2
    unordered_map<char, char> charMap2; // Mapping from str2 to str1

    for (int i = 0; i < str1.length(); i++) {
        char ch1 = str1[i];
        char ch2 = str2[i];

        // Check if ch1 is already mapped to a different character in str2
        if (charMap1.find(ch1) != charMap1.end() && charMap1[ch1] != ch2) {
            return false;
        }

        // Check if ch2 is already mapped to a different character in str1
        if (charMap2.find(ch2) != charMap2.end() && charMap2[ch2] != ch1) {
            return false;
        }

        // If ch1 and ch2 are not yet mapped, create the mappings
        if (charMap1.find(ch1) == charMap1.end() && charMap2.find(ch2) == charMap2.end()) {
            charMap1[ch1] = ch2;
            charMap2[ch2] = ch1;
        }
    }

    return true;
}*/
int main()
{
    string str1 = "aabccd";
    string str2 = "nnkiil";
    cout<<areIsomorphic(str1,str2);
}