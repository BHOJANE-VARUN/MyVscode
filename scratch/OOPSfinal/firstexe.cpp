#include<iostream>
using namespace std;
//need you stay
class Bank{
    //you are the reason i believe in love
    private:
    string name;
    int balance,withdrawal;
    public:
    Bank()
    {
//i be fucked up if you are not right there
        cout<<"Enter the name of the account holder:";
        getline(cin,name,'\n');
        cout<<"Enter the initial balance:";
        cin>>balance;
        withdrawal =0;
    }
//nobody good as you 
    void deposit()
    {
        int depo;
        cout<<"Enter amount to deposit:";
        cin>>depo;
        balance +=  depo;
        cout<<"Updated Balanced :"<<balance<<endl;
    }
//need you stay ,need to stay
    void withdraw()
    {
        cout<<"Enter the amount to withdraw:";
        cin>>withdrawal;
        if(withdrawal>balance)
        {
            cout<<"Insufficient balance to complete transcation"<<endl;
        }
        //i donot even need you love 
        else{
            balance -=  withdrawal;
            cout<<"Updated Balanced :"<<balance<<endl;
        }
    }
    //you donot have to cut me off
    void showdetails()
    {
        cout<<"Account Holder name:"<<name<<endl;
        cout<<"Balance:"<<balance<<endl;
    }
    //you just somebody used to know
};
int main()
{
    Bank obj;
    obj.deposit();
    obj.withdraw();
    obj.showdetails();
    return 0;
    //let it go 

}