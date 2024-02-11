#include<iostream>
using namespace std;
class personalinfo{
    public:
    string name,address;
    int age,tele;
    personalinfo(string nam,string add,int ag,int tel)
    {
        name = nam,address = add,age = ag,tele = tel;
    }
    void showpersonalinfo()
    {
        cout<<name<<endl;s
        cout<<address<<endl;
        cout<<age<<endl;
        cout<<tele<<endl;
    }
};
class officeinfo{
    public:
    string post,department;
    int officeid,salary;
    officeinfo(string pos,string depart,int offic,int salar)
    {
        post = pos,department = depart,officeid = offic,salary = salar;
    }
    void showofficeinfo()
    {
        cout<<post<<endl;
        cout<<department<<endl;
        cout<<officeid<<endl;
        cout<<salary<<endl;
    }
};
class Info:public personalinfo,public officeinfo
{

    public:
    string officeaddress;
    Info(string nam,string add,int ag,int tel,string pos,string depart,int offic,int salar,string off):personalinfo(nam,add,ag,tel),officeinfo(pos,depart,offic,salar)
    {
        officeaddress = off;
    }
    void show()
    {
        showpersonalinfo();
        showofficeinfo();
        cout<<officeaddress<<endl;
    }
};
int main()
{
    Info obj("varun sunil bhojane","yeola",19,696996,"CEO","AI and ML",171314,550000,"banglore");
    obj.show();
}
