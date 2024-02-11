#include <bits/stdc++.h> 
using namespace std;
std::string convertVectorToString(const std::vector<int>& vec) {
    std::ostringstream oss;
    
    // Iterate over the vector in reverse order
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        oss << *it ;
    }
    
    // Get the string representation
    std::string reverseString = oss.str();
    
    // Remove the trailing space
    if (!reverseString.empty()) {
        reverseString.pop_back();
    }
    
    return reverseString;
}
string bigfact(int n)
{  int ct = 1;
    vector<int> a(1,1);
    for (int i = 2; i <= n; i++)
    {   int temp =0;
        int j;
        for ( j = 0; j < ct; j++)
        {
            a.at(j)=temp+(a.at(j)*i);
            temp = a.at(j)/100000;
            a.at(j)=a.at(j)%100000;
            
         
        }
        if (temp>0 && j==ct)
            {
                a.push_back(temp);
                ct++;
            }   
    
        
        
    }
    string strans = convertVectorToString(a);
    return strans;
    
    /*vector<char> strans;
    for (auto i:a)
    {
      string strt =  to_string(i);
      strans.push_back(strt);
    }
    
  return strans; */  
}
int main()
{
   string  test = bigfact(19);
    cout<<test;
    
}