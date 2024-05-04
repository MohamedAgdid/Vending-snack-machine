#include <cstdlib> 
#include <ctime> 

class DropCheck{
   public:
    bool productReleased(){
      srand(time(0)); 
      return true;
      int random_number = rand() % 100; 
      if (random_number <= 9) {
            return false;
        } 
      else{  
          return true;
        }
    }

};
