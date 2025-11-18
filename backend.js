class trader{
    constructor(name, traderID, password){
        this.name = name;
        this.traderID = traderID;
        this.password = password;
        this.balance = 1000;
        this.ownedStocks = new Map();
    }
}

class stocks{
    constructor(name, ID, price, available){
        this.name = name;
        this.ID = ID;
        this.price = price;
        this.available = available;
    }
}

buyStock(key, val){
    this.ownedStocks.set(key, val);
    
}