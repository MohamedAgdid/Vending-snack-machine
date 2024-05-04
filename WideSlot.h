#include "Slot.h"
class WideSlot : public Slot {
    Motor *motor1; 
    Motor *motor2; 
public:
    WideSlot(int slotId, string productName, int price, int motor1Id, int motor2Id):Slot(productName, slotId, price, motor1Id, motor2Id) {
    motor1 = new Motor(motor1Id);
    motor2 = new Motor(motor2Id);
    }
    
    void drop() const{
    motor1->Trigger(motor1->getId());
    motor2->Trigger(motor2->getId());
    cout << "Produit livre a partir du logement " << getId() << endl;
}

};