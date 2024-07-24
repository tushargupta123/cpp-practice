class animal{
    constructor(name){
        this._name = name;
    }
    setName(name){
        this._name=name;
    }
    getName(){
        return this._name;
    }
}

class dog extends animal{
    getName(){
        return "Dog";
    }
}