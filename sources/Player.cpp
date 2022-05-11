#include <iostream>
#include "Player.hpp"
using namespace std;
using namespace coup;


  void  Player::income()
  {
    if((*this->game).turn()!=this->getName()||(*this->game).getList().size()<2)
    {
      throw "It's not yout turn";
     
    }
    if(this->coup1.empty())
    {
      this->coup1="";
    }
      this->setcoins(this->getcoins()+1);
    
        if (!(*this->game).playing)
    {
        (*this->game).playing=true;
    }
    this->fi=false;
          (*this->game).i++;

    
    
      }
  void  Player::foreign_aid()
  {
    if((*this->game).turn()!=this->getName()||(*this->game).getList().size()<2||(*this->game).getList().size()<2)
    {
      throw "It's not yout turn";
    } if(this->coins()>=(*this->game).maxcoins)
    {
        throw "how have too much coins";
    }
    
    this->setcoins(this->getcoins()+2);
    this->fi=true;
   (*this->game).i++;
    
    if (!(*this->game).playing)
    {
        (*this->game).playing=true;
    }
    
  }
    
  void  Player::coup(Player& p)
  {
    bool  a=false;
      unsigned long x=0;
      int i=(*this->game).exsist(p.getName());
      if (i==-1)
      {
        throw "Doesnt player";
      }
      
      if (this->getrole()=="Assassin")
      {
        if (this->coins()<3)
        {
          throw "bad move";
        }
        if (this->coins()<(*this->game).minCoup)
        {
          this->setcoins(this->coins()+4);
        }else{a=true;}
      } 
        if (this->coins()<(*this->game).minCoup)
    {
      throw "bad move";
      }
        this->setcoins(this->coins()-((*this->game).minCoup));
        if (!a)
        {
        this->coup1=p.getName();
        }
        
      x= (*this->game).removePlayer(p.getName());
      
      
      if(x%(*this->game).getList().size()>=this->game->i%(this->game->getList().size())){
       (*this->game).i++;
       
       }
        int w=this->game->exsist(this->getName());
       (*this->game).i=(unsigned long)(++w);

    
  
    if (!(*this->game).playing)
    {
        (*this->game).playing=true;
    }
    this->fi=false;
    }
    std::string Player::role()
    {
        return this->getrole();

    }
  
    int Player::coins() const
    {
     return this->getcoins();
    }
    //Player(coup::Game G,string s);
   Player::Player()
    {
     this->game=NULL;
     this->_coins=0;
     this->steal1=NULL;
    }
    void Player::inceaseCoins()
    {
        this->setcoins(this->getcoins()+1);
    }
    void Player::transfer(Player& p1,Player& p2)
    {
    if((*this->game).turn()!=this->getName()||this->getrole()!="Ambassador")
      {
        throw "It's not yout turn";
      }
        if (p1.coins()>0)
      {
   p1.setcoins(p1.coins()-1);
   p2.inceaseCoins();
       this->fi=false;

    }else
    {
      throw "bad move";
    }
      (*this->game).i++;    

  
  }

  void Player::tax(){
  if (this->getrole()!="Duke")
  {
    throw "error";
  }
  
  if ((*this->game).turn()!=this->getName())
  {
    throw "its not your turn";
  }
  
  this->setcoins(this->getcoins()+3);
  (*this->game).i++;
  
      this->fi=false;

}
void Player::steal(Player&p)
{
  if (this->getrole()!="Captain")
  {
    throw "error";
  }
  if ((*this->game).turn()!=this->getName())
  {
    throw "its not your turn";
  }
      
        if((&p)->coins()==0)
        {
          throw "this player dont have coins";
        }
      for (size_t i = 0; i < 2; i++)
      {
        if((&p)->coins()>0){
          (&p)->setcoins((&p)->coins()-1);
          this->inceaseCoins();
          }
      }
      
      (this->steal1)=(&p);
          this->fi=false;

      (*this->game).i++;
    
}
void Player::block(Player&p)
{
  if (this->getrole()=="Contessa")
  {
    if (!p.coup1.empty())
    {
      (&p)->coup1="";
              string s=this->game->turn();

      (*this->game).setList((this->game->prevl));      

 
        int w=this->game->exsist(s);

       (*this->game).i=(unsigned long)(w);

              //(*this->game).i++;


    }else{throw "bad move!";}

  }if (this->getrole()=="Duke")
  {
    if (p.fi)
    {
          p.setcoins(p.getcoins()-2);

    }else{
      throw "dont fi";
    }
  }if (this->getrole()=="Captain"||this->getrole()=="Ambassador")
  {
    if ((p.getrole()=="Captain"&&p.steal1!=NULL))
    {
      Player& p1=*p.steal1;
        (&p)->setcoins(p.coins()-2);
        (&p1)->setcoins((&p1)->getcoins()+2);
    }else{throw "bad movee";}
    
  }  
    this->fi=false;
}

