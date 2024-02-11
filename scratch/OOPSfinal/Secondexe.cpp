#include<iostream>
using namespace std;
class Student{
    private:
    string name;
    int Dm,oops,dedc,uhiv,coa;
    int total;
    public:
    Student(){
        cout<<"Enter Student name:";
        getline(cin,name,'\n');
        cout<<"Enter marks of Discrete mathematics:";
        cin>>Dm;
        cout<<"Enter marks of object oriented programming:";
        cin>>oops;
        cout<<"Enter marks of Digit Electronic and Data communication:";
        cin>>dedc;
        cout<<"Enter marks of Bulbasaur's subject:";
        cin>>uhiv;
        cout<<"Enter marks of Computer organziation and architecture:";
        cin>>coa;
        total = Dm+coa+oops+uhiv+dedc;
    }
    void totalmarks()
    {
        cout<<"total Marks:"<<total<<endl;
    }
    void average()
    {
        int average = total/5;
        cout<<"Average marks:"<<average<<endl;
    }
};
int main()
{
    Student obj;
    obj.totalmarks();
    obj.average();
    return 0;
}