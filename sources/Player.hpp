#include <iostream>
#pragma once
#include "Game.hpp"
using namespace std;
namespace coup{
    class Player
    {
    string _role;
    string _name;
    int _coins;
    public:
    void income();
    void foreign_aid();   
    void coup(Player&);
    string role();
    Game *game;
    string coup1="";
    Player  *steal1;
    int coins()const;
    bool fi=false;
    //Player(coup::Game G,string s);
    Player();
    void inceaseCoins();
    void setrole(string s){this->_role=s;}
    void setName(string n){this->_name=n;}
    string getrole(){return this->_role;}
    string getName(){return this->_name;}
    void setcoins(int c){this->_coins=c;}
    int getcoins( )const{return this->_coins;}
    void transfer(Player& p1,Player& p2);
    Player getPlayer(){return *this;}
    void tax();
    void steal(Player&);
    void block(Player&);
    };

}