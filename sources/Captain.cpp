#include <iostream>
#include "Captain.hpp"
#include "Player.hpp"
#include "Game.hpp"

Captain::Captain(Game& g,const string &s)
  {
    if (g.getList().size()>=g.MAX||g.playing)
    {
      throw logic_error("overflow") ;
    }
    this->setName(s);
     this->setcoins(0);
     this->setrole("Captain");
     g.addPlayer(s);
     this->game=&g;
    
  }

