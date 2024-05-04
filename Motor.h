#pragma once
#include <iostream>
using namespace std;
class Motor{
   int id; 
   public:
    Motor(int id=0){
    this->id = id;
};
    void Trigger(int id){
     cout<<"Moteur "<<id<<" est active."<<endl;
};
    int getId(){
    return id;   
    }

};

