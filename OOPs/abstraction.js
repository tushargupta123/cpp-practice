class animal{
    constructor(name){
        this._name = name;
    }
    setName(name){
        this._name=name;
    }
    getName(){
        throw new Error("It is to be implemented in derived classes");
    }
}

class dog extends animal{
    getName(){
        return "Dog";
    }
}