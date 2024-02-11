#include <bits/stdc++.h> 
using namespace std;
vector<int> findCommonElements(vector<int> &a, vector<int> &b, vector<int> &c)
{
    a.insert(a.end(),b.begin(),b.end());
    a.insert(a.end(),c.begin(),c.end());
    sort(a.begin(),a.end());
    int size = a.size();
    vector<int> vec(size,0);
    int j = -1;
    for (int  i = 0; i < size-2; i++)
    {
        if (a[i]==a[i+1] && a[i+1]==a[i+2])
        {   if (j == -1){
            vec[0]=a.at(i);
            j++;
        }
        else if (vec[j] == a.at(i))
        {
                    continue;
        }
        else
        {           j++;
                    vec[j]= a.at(i);
                    
                    
        }
        }
        
    }
    vec.resize(j+1);
    return vec;
    


}
int main()
{
    vector<int> vec = {4,3,345,35,3};
    vector<int> vec1 = {2,53,534,3,4};
    vector<int> vec2 = {2,4,3,53,5};
    vec = findCommonElements(vec,vec1,vec2);
    for (int i = 0; i < vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }
    
}