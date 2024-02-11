#include<iostream>
using namespace std;
class items
{
private:
 int amount; /* data */
 
public:
 void setamount(void){cout<<"enter a amount ";
  cin>>amount;
 };
 void giveamount(void){
  cout<<amount;
 };
};




int main()
{
  items apple;

  
  apple.setamount();
  apple.giveamount();
  
  
    
    
    return 0;
}
