#include <iostream>
#include "Ambassador.hpp"
#include "Player.hpp"
#include "Game.hpp"

  Ambassador::Ambassador(Game& g,const string &s)
  {
    if (g.getList().size()>=g.MAX||g.playing)
    {
      throw logic_error("overflow") ;
    }
    this->setName(s);
     this->setcoins(0);
     this->setrole("Ambassador");
     g.addPlayer(s);
     this->game=&g;
    
  }
  
  




