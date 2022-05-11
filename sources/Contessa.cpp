#include <iostream>
#include "Contessa.hpp"
#include "Player.hpp"
#include "Game.hpp"
using namespace coup;
  Contessa::Contessa(Game& g,const string &s)
  {
    if (g.getList().size()>=g.MAX||g.playing)
    {
      throw logic_error("overflow") ;
    }
    this->setName(s);
     this->setcoins(0);
     this->setrole("Contessa");
     g.addPlayer(s);
     this->game=&g;
    
  }




