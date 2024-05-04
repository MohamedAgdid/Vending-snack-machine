#include "Slot.h"
class SmallSlot : public Slot {
    Motor* motor1;
public:
    SmallSlot(int slotId, string productName, int price, int motor1Id=0):Slot(productName, slotId, price, motor1Id){
         motor1 = new Motor(motor1Id);
    }
    void drop() const{
        motor1->Trigger(motor1->getId());
        cout << "Produit livre a partir du logement " << getId() << endl;
    }
};

