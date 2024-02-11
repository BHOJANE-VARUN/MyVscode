#include<iostream>
using namespace std;
class Vechicle{
    int mileage,price;
    public:
    
    Vechicle(int mil,int pri)
    {
        mileage = mil;
        price = pri;
    }
    void showvech()
    {
        cout<<"mileage:"<<mileage<<endl;
        cout<<"price:"<<price<<endl;
    }
};
class Car : public Vechicle{
     int owershipcost,warrentyinyrs,seatcap;
    string fueltype;
    public:
   
    Car(int mil,int pri,int owershi,int warrent,int seatc,string fuel):Vechicle(mil,pri)
    {
        owershipcost = owershi;
        warrentyinyrs = warrent;
        seatcap = seatc;
        fueltype = fuel;
    }
    void showcar()
    {
        showvech();
        cout<<"owershipcost:"<<owershipcost<<endl;
        cout<<"warrenty in yrs:"<<warrentyinyrs<<endl;
        cout<<"seat capacity:"<<seatcap<<endl;
        cout<<"fueltype:"<<fueltype<<endl;
    }
};
class bike:public Vechicle{
    int cylin,gears,fueltanksize;
    string coolingtype,wheeltype,modeltype;
    public:
    
    bike(int cyl,int gea,int fuel,int mil,int pri,string cool,string wheel,string model):Vechicle(mil,pri)
    {
        cylin = cyl,gears = gea,fueltanksize = fuel,coolingtype = cool,wheeltype = wheel,modeltype = model;
    }
    void showbike()
    {
        showvech();
        cout<<"cylinders:"<<cylin<<endl;
        cout<<"gears:"<<gears<<endl;
        cout<<"fuel tank size:"<<fueltanksize<<endl;
        cout<<"cooling type:"<<coolingtype<<endl;
        cout<<"wheel type:"<<wheeltype<<endl;
        cout<<"model type:"<<modeltype<<endl;
    }
};
class Audi:public Car{
    string modelname;
    public:
    
    Audi(int mil,int pri,int owershi,int warrent,int seatc,string fuel,string modelnam):Car(mil,pri,owershi,warrent,seatc,fuel)
    {
        modelname = modelnam;
    }
    void showAudi(){
        showcar();
        cout<<"model name:"<<modelname<<endl;
    }
};
class Ford:public Car{
    string modelname;
    public:
    
    Ford(int mil,int pri,int owershi,int warrent,int seatc,string fuel,string modelnam):Car(mil,pri,owershi,warrent,seatc,fuel)
    {
        modelname = modelnam;
    }
    void showFord(){
        showcar();
        cout<<"model name:"<<modelname<<endl;
    }
};
class Bajaj:public bike
{
    string themaketype;
public:
    
    Bajaj(int cyl,int gea,int fuel,int mil,int pri,string cool,string wheel,string model,string make):bike(cyl,gea,fuel,mil,pri,cool,wheel,model)
    {
        themaketype = make;
    }
    void showBajaj(){
        showbike();
        cout<<"the make type:"<<themaketype<<endl;
    }
};
class TVS:public bike
{
    string themaketype;
public:
    
    TVS(int cyl,int gea,int fuel,int mil,int pri,string cool,string wheel,string model,string make):bike(cyl,gea,fuel,mil,pri,cool,wheel,model)
    {
        themaketype = make;
    }
    void showTVS(){
        showbike();
        cout<<"the make type:"<<themaketype<<endl;
    }
};
int main()
{
    TVS obj(3,4,59,100,15000,"liquid","alloy","latest","varun");
    obj.showTVS();
    Audi obj2(100,2000000,5000,8,4,"diesel","x3");
    cout<<endl;
    obj2.showAudi();
    return 0;
}