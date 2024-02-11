#include<iostream>
using namespace std;
class Matrix{
    public:
    int n,m;
    int arr[100][100];
    Matrix(int x,int y,int num)
    {
        n = x,m = y;
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                arr[i][j] = num;
            }
        }
    }
    Matrix(int x,int y){
        n = x,m = y;
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<"Enter "<<i<<"th row and "<<j<<"th column:";
                cin>>arr[i][j];
            }
        }
    }
    Matrix add(Matrix& a)
    {
        try
        {
            if(a.n!=n or a.m!=m)
            {
                throw(-1);
            }
            else{
                Matrix temp(a.n,a.m,0);
                for(int i =0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        temp.arr[i][j] = a.arr[i][j] + arr[i][j];
                    }
                }
                return temp;
            }
        }
        catch(int e)
        {
            cout<<"invalid parameters"<<endl;
        }
        
    }
    void show()
    {
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               // cout<<"Enter "<<i<<"th row and "<<j<<"th column:";
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    try
    {
        cout<<"Enter first matrix row and column:";
        int n,m;
        cin>>n>>m;
        if(n>=100 and m>=100) throw(-1);

        Matrix obj1(n,m);

        cout<<"Enter second matrix row and column:";
        int n1,m1;
        cin>>n1>>m1;
        if(n1>=100 and m1>=100) throw(-1);
        obj1.show();
        Matrix obj2(n1,m1);
        obj2.show();
        Matrix ans = obj1.add(obj2);
        ans.show();
    }
    catch(int e)
    {
         cout<<"invalid parameter"<<endl;   
    }
    
    
}