#include <iostream>
#include "Player.hpp"
class Game;
using namespace std;
using namespace coup;

class Assassin: public Player
{

  public:
    //Assassin():Player(){};
      Assassin(Game& ,const string& s);
    //Assassin(coup::Game G,string s);
};