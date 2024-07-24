class animal{
    private:
        string name;
    public:
        void setName(string n){
            name=n;
        }
        virtual string getName() = 0 // pure virtual function has to be overridden in derived classes
}

class dog : public animal{
    public:
        string getName() override{
            return "Dog";
        }
}