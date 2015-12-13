// Experiment3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include"Chain.h"
using namespace std;


int main(){
    chain<int>  *mychain;
    mychain= new chain<int>[100];
    cout << "Input sum of your nodelist:" << endl;
    int num = 0;
    int value=0,forvalue,result;
    cin >> num;
    cout << "Please input elements:" << endl;
    for (int i = 0; i < num; i++){
        cin >> value;
        mychain->insert(i, value);
    }
    mychain->print();
    int yuansu;
    cout << "input element to delete:" << endl;
    cin >> yuansu;
    mychain->shanchu(yuansu);
    mychain->print();
    
        mychain->reverseprint();
        cout << endl;
        cout << "input the value :" << endl;
    
        cin >> forvalue;
        result=mychain->indexOf(forvalue);
        cout << result << endl;
        cout << endl;
        mychain->hebing();
    return 0;
}