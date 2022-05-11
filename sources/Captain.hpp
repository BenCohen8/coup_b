#include <iostream>
#include "Player.hpp"
class Game;
using namespace coup;
class Captain:public Player
{
  public:
    Captain(Game& ,const string &s);
    Player steal1;
    };