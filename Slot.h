#include <iostream>
#include "Motor.h"
using namespace std;
#pragma once
class Slot {
    protected:
    string productName;
    int id;
    int numProducts;
    int price;
    Motor* motor1;
    Motor* motor2;
    public:
    Slot(string productName, int id, int price, int motorID1, int motorID2 = 0)
    : productName(productName), id(id), price(price), numProducts(0), motor1(nullptr), motor2(nullptr) {
   
    };
    virtual ~Slot(){
    delete motor1;
    delete motor2;
}; 
    virtual void drop() const = 0;
    string getProductName(){
    return productName;
};
    void setProductName(string prodname){
    productName = prodname;
};
    int getNumProducts(){
    return numProducts;
};
    void setNumProducts(int numProducts){
    this->numProducts = numProducts;
};
    int getPrice(){
    return price;
};
    void setPrice(int price){
    this->price = price;
};
    int getId() const{
    return id;
};
};