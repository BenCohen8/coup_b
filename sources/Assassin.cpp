#include <iostream>
#include "Assassin.hpp"
#include "Player.hpp"
#include "Game.hpp"

  Assassin::Assassin(Game& g,const string &s)
  {
    if (g.getList().size()>=g.MAX||g.playing)
    {
      throw logic_error("overflow") ;
    }
    this->setName(s);
     this->setcoins(0);
     this->setrole("Assassin");
     g.addPlayer(s);
     this->game=&g;
    
  }
    

