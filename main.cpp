#include "animal.h"
#include "Enor.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;


bool emptyFile(const string &filename)
{
    Enor t(filename);
    t.first();
    if(t.end()) {
        return true;
    } else {
        return false;
    }
}

int main(){

    vector<Prey*> preys;
    vector<Predators*> predators;

    string filename = "animals.txt";

    try{
        /*if(emptyFile(filename)) {
            cerr << "Empty file\n";
            return 1;
        }*/
        Enor t(filename);
        t.readfirstline();
        for(t.first(); !t.end(); t.next()){
            string nick = t.current().nickname;
            int num = t.current().num;
            switch(t.current().type){                
                case 'l':
                    preys.push_back(new Lemming(nick,num));
                    break;
                case 'n':
                    preys.push_back(new Rabbit(nick,num));
                    break;
                case 'u':
                    preys.push_back(new Hamster(nick,num));
                    break;
                case 'h':
                    predators.push_back(new SnowOwl(nick,num));
                    break;
                case 's':
                    predators.push_back(new ArticFox(nick,num));
                    break;
                case 'f':
                    predators.push_back(new Wolf(nick,num));
                    break;                
                default:
                    break;
            }
        }
        for(int i=0; i< preys.size(); i++){
            cout << preys[i]->get_nickname() << endl;            
        }
        for(int i=0; i< predators.size(); i++){
            cout << predators[i]->get_nickname() << endl;            
        }

    }
    catch(Enor::Exception exp) {
        cerr << "Open error!";
        return 2;
    }

    for (int round=0;;round++){


        bool end_simulation_condition=false;
        for (auto x : preys){
            if (x->get_starter_num()*4<=x->get_num()){
                end_simulation_condition=true;
                break;
            }
            if (x->get_num()<=0){
                end_simulation_condition=true;
                break;
            }
        }
        if (end_simulation_condition){
            break;
        }
    }



    for (auto x : preys){
        delete x;
    }

    for (auto x : predators){
        delete x;
    }




    return 0;
}
