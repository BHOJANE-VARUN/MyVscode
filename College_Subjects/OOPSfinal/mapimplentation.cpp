#include<iostream>
#include<map>
using namespace std;

int main(){
    map<string, pair<string, int>> obj;
    int n;

    //Storing data in map
    cout<<"Enter the number of entries"<<endl;
    cin>>n;
    string name;
    string bday;
    int telnum;
    for(int i=0; i<n ;i++){
        
        cout<<"Enter the name of person"<<endl;
        cin>>ws;
        getline(cin,bday);
        cout<<"Enter the birthday of the person"<<endl;
        cin>>ws;
        getline(cin,bday);
        cout<<"Enter the mobile number of the person"<<endl;
        cin>>telnum;

        obj[name] = make_pair(bday, telnum);
    }
    
    //Display data form the map
    cout<<"The entreies are : "<<endl;
    for(const auto &op : obj){
        cout<<"Name : "<<op.first<<" "<<"Birthday : "<<op.second.first<<" "<<"Telephone number : "<<op.second.second<<" "<<endl;
    }

    return 0;
}