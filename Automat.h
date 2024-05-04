#include "Slot.h"
#include "CoinSlot.h"
#include "Keypad.h"
#include "DropCeck.h"
#include <vector>
#pragma once

class Automat {
    vector<Slot*> slots;
    int numSlot;
    int numProductsPerSlot;
    vector<Slot*> cached; 
    CoinSlot coinSlot;
    Keypad keypad;
    DropCheck dropCheck;
    public:
     Automat(int numSlots=0,int numProductsPerSlot=0){
    this->numSlot = numSlots;
    this->numProductsPerSlot = numProductsPerSlot;
}
     ~Automat(){
      for(Slot* slot : slots){
            delete slot;
      }
}

    bool addSlot(Slot* slot){
    slots.push_back(slot);
    return true;
}
     Slot* searchSlot(int slotid){
    for(Slot* slot : slots) {
        if(slot->getId() == slotid) {
            return slot;
        }
    }
}
     void changeSlot(int slotid,string name,int price){
    for(Slot* slot:slots){
      if(slot->getId()==slotid){
        slot->setProductName(name);
        slot->setPrice(price);
      }
     }}
     int getPrice (int slotid){
    for(Slot* slot:slots){
      if(slot->getId()==slotid){
        return slot->getPrice();
      }}}
     int getNumPieces(int slotid){
   for(Slot* slot:slots){
      if(slot->getId()==slotid){
        return slot->getNumProducts();
      }}
      }
    bool isAvailable(int slotid) const{
    for(Slot* slot:slots){
      if(slot->getId()==slotid){
        return true;
      }}
      return false;
      }
     bool dropSlot(int slotid){
    if(isAvailable(slotid)==true){
    return true;
      
    }
    else return false;
}
     void fillAll (int numProductsPerSlot){
   this->numProductsPerSlot=numProductsPerSlot;
}
     
     void fill(int slotid, int numProducts){
    for(Slot* slot:slots){
      if(slot->getId()==slotid){
         slot->setNumProducts(numProducts);
      }}
}
    Keypad& getKeypad() {
    return keypad;
    }

    CoinSlot& getCoinSlot() {
    return coinSlot;
    }

    DropCheck& getDropCheck() {
    return dropCheck;
    }
    vector<Slot*> getSlots() const {
        return slots;
    }
};
