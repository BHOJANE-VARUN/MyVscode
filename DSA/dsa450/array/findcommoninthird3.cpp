#include <bits/stdc++.h> 
using namespace std;
void display(vector<int> vec)
{
    for(int i = 0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
vector<int> findCommonElements(vector<int> &a, vector<int> &b, vector<int> &c)
{
    int ii = 0;
    int ij = 0;
    int ik = 0;
    int var = -1;
    vector<int> vec;
        while (ii<a.size() && ij<b.size() && ik<c.size())
        {
            if (a[ii] == b[ij] && b[ij] == c[ik])
            {   if(var==-1)
                {
                    vec.push_back(a.at(ii));
                    var++;
                    ii++, ij++, ik++;

                }
                else if (vec.back() == a[ii])
                {
                    ii++, ij++, ik++;
                }
                else
                {   int temp = a.at(ii);
                    vec.push_back(temp);
                    ii++, ij++, ik++;
                }
            }
            if (a[ii] < b[ij] || a[ii] < c[ik])
            {
                ii++;
            }
            else if (a[ii] > b[ij] || b[ij] < c[ik])
            {
                ij++;
            }
            else if (c[ik] < b[ij] || a[ii] > c[ik])
            {
                ik++;
            }
        }
        return vec;
    
}
int main()
{
    vector<int> vec = {4,3,345,35,3};
    vector<int> vec1 = {2,53,534,3,4};
    vector<int> vec2 = {2,4,3,53,5};
    sort(vec.begin(),vec.end());
    sort(vec1.begin(),vec1.end());
    sort(vec2.begin(),vec2.end());
    display(vec);
    display(vec1);
    display(vec2);
    

    vec = findCommonElements(vec,vec1,vec2);
    for (int i = 0; i < vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }
    
}