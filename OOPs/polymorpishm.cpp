class animal{
    private:
        string name;
    public:
        void setName(string n){
            name=n;
        }
        virtual string getName(){
            return name;
        }
}

class dog : public animal{
    public:
        string getName() override{
            return "Dog";
        }
}