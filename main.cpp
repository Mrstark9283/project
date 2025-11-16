#include<iostream>
#include<map>
using namespace std;

int id = 1;

class trader{
public:
    string name;
    int traderID, password;
    int balance = 1000;
    map<string,int> stocks = {{"TATA",30},{"JIO", 10}};

    void buyStock(string key, int val){stocks[key] = val;}

    void profile(){
        cout<<"<-------------------------------------->"<<endl;
        cout<<"TRADER PROFILE"<<endl;
        cout<<"NAME : " <<name<<endl;
        cout<<"BALANCE : "<<balance<<endl;
        cout<<"Stocks Owned"<<endl;
        for(const auto& pair : stocks){
        cout<< pair.first<<" : "<<pair.second<<endl;
        }
        cout<<"<-------------------------------------->"<<endl;
    }

    trader(){}

    trader(string n,int ID, int pass, int bal){
        name = n;
        traderID = ID;
        password = pass;
        balance = bal;
    }

    void createProfile(){
        cout<<"create trader profile"<<endl;
        cout<<"NAME : ";
        cin>>name;
        cout<<"PASSWORD : ";
        cin>>password;
        cout<<"profile successfully created"<<endl;
        cout<<"your trader ID is : "<<id<<endl;
        id++;
    }

};

int main(){
    trader t1;
    t1.createProfile();
    t1.profile();
}

//g++ main.cpp -o main && ./main.exe
