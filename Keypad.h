class Keypad{
     public:
      int getSelection(){
    int empl;
    do{
    cout<<"saisir le numero de l\'emplacement du produit : ";
    cin>>empl;
    if(empl ==-1){
      return -1;
    }
    }while(empl<0);  
    return empl;   }   
  
};