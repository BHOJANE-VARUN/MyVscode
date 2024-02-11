#include<iostream>
using namespace std;
class Vechicle
{
private:
    int price,mileage;
public:
    Vechicle();
    //~Vechicle();
    void getvechicle()
    {
        cout<<price<<endl<<mileage<<endl;
    }
};

Vechicle::Vechicle()
{
    cout<<"enter the price and mileage:";
    cin>>price>>mileage;
}
class car: public Vechicle
{
private:
    int cost,warrenty,seats;
    string fuel;
public:
    car();
    void getcar()
    {
        getvechicle();
        cout<<cost<<endl<<warrenty<<endl<<seats<<endl;
    }
};

car::car()
{
   // Vechicle();
    cout<<"enter the cost ,warrenty(in yrs) ,no of seats:";
    cin>>cost>>warrenty>>seats;
    cout<<"enter the fuel type:";
    cin>>fuel;
}
class Bike :public Vechicle
{
private:
    int cylinder,gears,fueltanksize;string cooling,wheeltype;
public:
    Bike();
};

Bike::Bike()
{
    //Vechicle();
    cout<<"enter the cylinderno,no of gears,fueltanksize:";
    cin>>cylinder>>gears>>fueltanksize;
    cout<<"enter the cooling type and wheeltype:";
    cin>>cooling>>wheeltype;
}
class Audi:public car{
    private:
    string modeltype;
    public:
    Audi()
    {
        //car();
        cout<<"enter the model of Audi car";
        cin>>modeltype;
    }
    void getaudi()
    {
        getcar();
        cout<<modeltype<<endl;
    }
};
int main()
{
    Audi obj;
    obj.getaudi();
}



