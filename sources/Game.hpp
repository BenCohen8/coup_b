#include <iostream>
#include <vector>
#pragma once
using namespace std;


    class Game
    { 
        private:
            vector<string> playerslist;
        public:
            const  int minCoup=7;
            const int maxcoins=10;
            int MAX=6;
            vector<string> prevl;
            unsigned long i=0;
            bool playing=false;
            vector<string> players();
            string turn(){return this->playerslist.at((this->i)%this->playerslist.size());};
            void addPlayer(string);
            Game();
            unsigned long removePlayer(const string & p);
            vector<string> getList(){return this->playerslist;} 
            void setList(vector<string> s){this->playerslist=s;};
            void updateList(string s){this->playerslist.push_back(s);}
            string winner();
            int exsist(const string&);
    };

