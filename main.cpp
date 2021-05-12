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
    t.readfirstline();
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
        if(emptyFile(filename)) {
            cerr << "Empty file!\n";
            return 1;
        }
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
            cout << preys[i]->get_nickname() << " " << preys[i]->get_num() << endl;
        }
        for(int i=0; i< predators.size(); i++){
            cout << predators[i]->get_nickname() << " " << predators[i]->get_num() << endl;
        }

    }
    catch(Enor::Exception exp) {
        cerr << "Open error!";
        return 2;
    }

    int preys_start_sum = 0;
    for(int i=0; i< preys.size(); i++){
        preys_start_sum += preys[i]->get_starter_num();
    }
    cout << preys_start_sum << endl;

    for(int round=0;;round++){
        int preys_curr_sum = 0;

        //...


        for(auto x : preys){
            preys_curr_sum += x->get_num();
        }
        if(preys_start_sum*4 < preys_curr_sum || preys_curr_sum <= 0){
            break;
        }
    }

    for(auto x : preys){
        delete x;
    }
    for(auto x : predators){
        delete x;
    }

    return 0;
}
