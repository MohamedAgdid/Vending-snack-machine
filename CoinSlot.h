#include <iostream>
#include <vector>
using namespace std;
class CoinSlot{
    int insertedAmount;
    vector<int> coinValues={200,100,50,20,10,5,1};
    public:
     CoinSlot();
     int updateCoinAmount();
     int getCoinAmount();
     void clear();
     void returnCoins(int price);
};
CoinSlot::CoinSlot(){
    insertedAmount=0;
}
int CoinSlot::updateCoinAmount(){
  int nbr;
  cout<<"vieullez inserer une piece ou entrer -1 pour annuler le processus d\'achat : ";
  cin>>nbr;
  if(nbr!=-1){
    insertedAmount+=nbr;
    cout<<" le montant est : "<<insertedAmount<<endl;
  }
  else{
    cout<<"le processus est annuler."<<endl;
  }
  return insertedAmount;
}
int CoinSlot::getCoinAmount(){
    return insertedAmount;
}

void CoinSlot::clear(){
    insertedAmount=0;
}
void CoinSlot::returnCoins(int price){
    if(insertedAmount<price){
      cout<<"montant  est  insuffisant, votre montant maintenent : "<<insertedAmount<<endl;
      cout << endl << endl << endl;
    }
    else{
    insertedAmount -= price;
    if(insertedAmount==0){
      cout << "Return coins: 0";
      cout << endl << endl << endl;
    }
    else{
            cout << "Return coins: ";
            bool first = true;
            for (int coin : coinValues) {
                int count = insertedAmount / coin;
                if (count > 0) {
                    if (!first) {
                        cout << " + ";
                    }
                    cout << count << " * " << coin;
                    insertedAmount -= count * coin;
                    first = false;
                }
            }
          cout << endl << endl << endl;
        }
    }
    }