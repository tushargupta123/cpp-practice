class animal{
    private:
        string name;
    public:
        void setName(string n){
            name=n;
        }
        string getName(){
            return name;
        }
}

class dog : public animal{
    public:
        void bark(){
            cout<<"bark"<<endl;
        }
}