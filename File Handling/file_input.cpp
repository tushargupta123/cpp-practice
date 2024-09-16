#include<fstream>
#include<iostream>
#include<string>
using namespace std;

int main(){
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    if(!inputFile.is_open()){
        cout<<"Error: Could not open input file!"<<endl;
        return 0;
    }
    string line;
    while(getline(inputFile,line)){
        outputFile<<line<<endl;
    }
    inputFile.close();
    outputFile.close();
    cout<<"File processed successfully!"<<endl;
    return 0;
}