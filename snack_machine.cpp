#include <iostream>
#include "Automat.h"
#include "Motor.h"
#include "SmallSlot.h"
#include "WideSlot.h"
#include <iomanip>
using namespace std;

enum Etat {
    IDLE,
    COLLECT_MONEY,
    DROP,
    RETURN_MONEY,
    RETURN_MONEY_EXIT
};

int main() {
    Automat automat(15,20);
    automat.addSlot(new SmallSlot(1, "tonic", 1, 1)); 
    automat.addSlot(new WideSlot(2, "hohos", 2, 2, 2));
    automat.addSlot(new WideSlot(3, "hirnis", 2, 3, 3));
    automat.addSlot(new WideSlot(4, "Corny", 2, 4, 4));
    automat.addSlot(new SmallSlot(5, "Snickers", 3, 5)); 
    automat.addSlot(new WideSlot(6, "Kitkat", 3, 6, 6));
    automat.addSlot(new SmallSlot(7, "Twix", 2, 7)); 
    automat.addSlot(new WideSlot(8, "m&ms", 2, 8, 8));
    automat.addSlot(new SmallSlot(9, "mars", 2, 9)); 
    automat.addSlot(new WideSlot(10, "Reese", 2, 10, 10));
    automat.addSlot(new SmallSlot(11, "Golden", 1, 11)); 
    automat.addSlot(new WideSlot(12, "Sable", 1, 12, 12));
    automat.addSlot(new SmallSlot(13, "tagger", 1, 13)); 
    automat.addSlot(new WideSlot(14, "Merrendina", 2, 14,14));
    automat.addSlot(new WideSlot(15, "tango", 1, 15, 15));

    Etat etat = IDLE;
    int x = -1; 
    int coinAmount;
    Slot* slot = nullptr; 
    bool ok=true;
    while (ok) {
        switch (etat) {
            case IDLE:
                cout << left << setw(7) << "ID Emp" << "|" << setw(15) << "Product Name" << "|" << "Price" << endl;
                cout << "---------------------------------------------" << endl;
                for (Slot* slot : automat.getSlots()) {
                cout << left << setw(7) << slot->getId() << "| " << setw(15) <<
                slot->getProductName()<< "| " << slot->getPrice()<<" Euro"<< endl;
                }
                cout << "---------------------------------------------" << endl;

                x = automat.getKeypad().getSelection();
                if (x == -1) {
                    etat = RETURN_MONEY_EXIT;

                } else {
                    if (automat.isAvailable(x)) {
                        etat = COLLECT_MONEY;
                    } else {
                        cout << "Aucun produit disponible" << endl;
                        etat = RETURN_MONEY;
                    }
                }
                break;

            case COLLECT_MONEY:
                coinAmount = automat.getCoinSlot().updateCoinAmount(); 
                if (coinAmount == -1) {
                    etat = RETURN_MONEY_EXIT;
                } else {
                    if (coinAmount >= automat.getPrice(x)) {
                        if (automat.getDropCheck().productReleased()) {
                            etat = DROP;
                        } else {
                            etat = RETURN_MONEY;
                        }
                    } else {
                        cout << "Fonds insuffisants" << endl;
                        etat = RETURN_MONEY;
                    }
                }
                break;

            case DROP:
                 system("cls");
                slot = automat.searchSlot(x);
                if (automat.dropSlot(x)) {
                    slot->drop();
                }
                if (automat.getDropCheck().productReleased()) {
                    cout << boolalpha << "Drop : " << slot->getProductName() << endl;
                    etat = RETURN_MONEY;
                } else {
                    cout << "Produit non publie. Nouvel essai..\n";
                    etat = IDLE;
                }
                break;

            case RETURN_MONEY:
                automat.getCoinSlot().returnCoins(automat.getPrice(x));
                etat = IDLE;
                break;
            
            case RETURN_MONEY_EXIT:
                automat.getCoinSlot().clear();
                ok=false;
                break;
        }
    }

    return 0;
}
