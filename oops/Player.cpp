#include<iostream>
using namespace std;

class Player{
    int health;

    public: 
        char level;

        int getHealth(){
            return health;
        }

        // Player(int health, char level){
        //     this->health=health;
        //     this->level=level;
        // }

        // Player(Player &temp){
        //     health=temp.health;
        //     level=temp.level;
        // }

        void setHealth(int health){
            this->health=health; //this stores the address of the current object 
        }
};  
