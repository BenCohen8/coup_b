#include "Game.hpp"
#include <iostream>
#include <vector>
using namespace std;
Game::Game(){
     vector<string> v;
     this->setList(v);
}
vector<string> Game::players()
{
     
     return this->getList();
}

void Game::addPlayer(string s)
{
     this->updateList(move(s));
}
string Game::winner()
{
     if (this->getList().size()>1)
     {
          throw "Game still playing";
     }
     if(!this->playing){

          throw "Game dont begin";
     }
     
      return this->getList().at(0);
}
unsigned long Game::removePlayer(const string &p)
{
     unsigned long j=0;
     vector<string> t;
     for (size_t i = 0; i < this->getList().size(); i++)
     {
          if(this->getList().at(i)!=p)
          {
               t.push_back(this->getList().at(i));
          }else{j=i;}
     }
     this->prevl=this->getList();
     this->setList(t);
     t.clear();
     return j;
     
}
int Game::exsist(const string &p)
{
     int j=-1;
     for (size_t i = 0; i < this->getList().size(); i++)
     {
          if(this->getList().at(i)!=p)
          {
          }else{j=i;}
     }
     return j;
     
}
      


