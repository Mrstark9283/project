#include<iostream>
#include<map>
using namespace std;

int id = 1;

class stock{
public:
    string stockName;
    int stockID, pricePerUnit, availableUnits;

    stock(){}

    stock(string name, int ID, int price, int units){
        stockName = name;
        stockID = ID;
        pricePerUnit = price;
        availableUnits = units;
    }
};

class trader{
public:
    string name;
    int traderID, password;
    int balance = 1000;
    map<string,int> ownedStocks;

    void addStock(string key, int val){ ownedStocks[key] += val; }

    void profile(){
        cout<<"<-------------------------------------->"<<endl;
        cout<<"TRADER PROFILE"<<endl;
        cout<<"NAME : " <<name<<endl;
        cout<<"BALANCE : "<<balance<<endl;
        cout<<"Stocks Owned"<<endl;
        for(const auto& pair : ownedStocks){
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
        traderID = id;
        cout<<"profile successfully created"<<endl;
        cout<<"your trader ID is : "<<id<<endl;
        id++;
    }

};

map<int,trader> traders;
map<int,stock> stocks;

void buyStock(trader &t, stock &s, int quantity){
    int totalCost = s.pricePerUnit * quantity;
    if(t.balance >= totalCost && s.availableUnits >= quantity){
        t.balance -= totalCost;
        s.availableUnits -= quantity;
        t.addStock(s.stockName, quantity);
        cout<<"Purchase successful!"<<endl;
    } else {
        cout<<"Insufficient balance or stock units!"<<endl;
    }
}

void displayStocks(map<int, stock> &stocksMap){
    cout<<"<-------------------------------------->"<<endl;
    cout<<"AVAILABLE STOCKS"<<endl;
    for(const auto& pair : stocksMap){
        cout<<"STOCK ID : "<< pair.first << endl;
        cout<<"STOCK NAME : "<< pair.second.stockName << endl;
        cout<<"PRICE PER UNIT : "<< pair.second.pricePerUnit << endl;
        cout<<"AVAILABLE UNITS : "<< pair.second.availableUnits << endl;
        cout<<"<-------------------------------------->"<<endl;
    }
}

void CreateProfile(){
    trader t;
    t.createProfile();
    traders[t.traderID]=t;
    t.profile();
    
}

int main(){

    cout<<"Welcome to Stock Trading Platform"<<endl;
    cout<<"Create your trader profile to start trading"<<endl;

    CreateProfile();
    traders[1].balance = 5000;
    cout<<"4000 rupees bonus credited"<<endl;

    stock s("TATA", 1, 300,10);

    buyStock(traders[1],s,5);

    traders[1].profile();

    return 0;
}

//g++ main.cpp -o main && ./main.exe