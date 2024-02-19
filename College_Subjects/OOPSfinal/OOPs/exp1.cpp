#include<iostream>
#include<string>
using namespace std;
class Bank{
    private:
    string name;
    int accountNo,Balance,withdr;
    public:
    Bank(int bal,string nam,int no)
    {
        if(bal<0)
        {
            Balance =0;
        }
        else{
            Balance = bal;
        }
        withdr = 0;
        name = nam;
        accountNo = no;
    }
    void deposit(int bal)
    {
        Balance += bal;
        cout<<"updated balance is "<<Balance<<endl;
    }
    void withdraw(int val)
    {
        if(Balance>=val)
        {   withdr = val;
            Balance -= val;
            cout<<"updated balance is "<<Balance<<endl;
        }
        else{
            cout<<"insufficienct balance to perform transcation"<<endl;
        }
    }
    void show()
    {
        cout<<"Account no is "<<accountNo<<endl
        << "account details:"<<endl
        <<name<<endl
        <<Balance<<endl;
    }
    void previouswithdrawal();
};
void Bank::previouswithdrawal()
{
    cout<<"previously withdrawal amount is :"<<withdr<<endl;
}
int main()
{
    string name;
    int bal,acc;
    cout<<"enter the initial bank account detail:"<<endl;
    cout<<"enter name:";
    cin>>name;
    cout<<"enter intial balance:";
    cin>>bal;
    cout<<"enter the acc:";
    cin>>acc;
    Bank obj(bal,name,acc);
    int ch;
    cout<<"welcome to Bank services"<<endl;
    while (ch!=0)
    {   
        cout<<"Enter 1 to withdraw , 2 for deposit , 3 to see account details ,4 to see previous trancstion, 0 to stop"<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            int val;
            cout<<"enter the withdrawal value :";
            cin>>val;
            obj.withdraw(val);
            break;
        case 2:
            int va;
            cout<<"enter the deposit value :";
            cin>>va;
            obj.deposit(va);
            break;
        case 3:
            obj.show();
            break;
        case 4:
            obj.previouswithdrawal();
            break;
        default:
            break;
        }
    }
    cout<<"Thank you using for our service"<<endl;
}