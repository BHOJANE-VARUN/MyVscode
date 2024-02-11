#include<iostream>
using namespace std;
class PersonInfo{
    string name,bloodgrp,address;
    int height,weigth,policyno,telenum,drivinglicen;
    public:
    //deflaut constructor
    PersonInfo()
    {
        cout<<"name:";
        getline(cin,name,'\n');
        cout<<"blood group:";
        cin>>bloodgrp;
        cout<<"address:";
        cin>>ws;
        getline(cin,address,'\n');
        cout<<"height:";
        cin>>height;
        cout<<"weigth:";
        cin>>weigth;
        cout<<"policy number:";
        cin>>policyno;
        cout<<"telephone no:";
        cin>>telenum;
        cout<<"driving liscense no:";
        cin>>drivinglicen;
    }
    //parametrized constructor
    PersonInfo(string nav,string blood,string add,int heig,int weig,int policy,int tele,int drivin)
    {
        name = nav;
        bloodgrp = blood;
        address = add;
        height = heig;
        weigth = weig;
        policyno = policy;
        telenum = tele;
        drivinglicen = drivin;
    }
    PersonInfo(PersonInfo& a)
    {
        name = a.name;
        bloodgrp = a.bloodgrp;
        address = a.address;
        height = a.height;
        weigth = a.weigth;
        policyno = a.policyno;
        telenum = a.telenum;
        drivinglicen = a.drivinglicen;
    }
    ~PersonInfo()
    {
         name.clear(),bloodgrp.clear(),address.clear(),height =0,weigth=0,policyno=0,telenum=0,drivinglicen=0;
    }
};
int main()
{
    PersonInfo obj;
    PersonInfo obj2("varun","o-","yeola",6,120,696969,1714,80085);
    PersonInfo obj3(obj2);
    return 0;
}