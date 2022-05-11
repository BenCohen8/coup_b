#include <iostream>
#include "Duke.hpp"
#include "Player.hpp"
using namespace coup;
  Duke::Duke(Game& g,const string &s)
  {
    if (g.getList().size()>=g.MAX||g.playing)
    {
      throw logic_error("overflow") ;
    }
    this->setName(s);
     this->setcoins(0);
     this->setrole("Duke");
     g.addPlayer(s);
     this->game=&g;
    
  }
  





