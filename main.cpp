#include "animal.h"
#include "Enor.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void printState(vector<Prey*> &preys, vector<Predators*> &predators){
    for(int i=0; i< preys.size(); i++){
        cout << preys[i]->get_nickname() << " " << preys[i]->get_num() << endl;
    }
    for(int i=0; i< predators.size(); i++){
        cout << predators[i]->get_nickname() << " " << predators[i]->get_num() << endl;
    }
}

int main(int argc,char *argv[]){

    srand ( (unsigned int) time(nullptr));

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
    }
    catch(Enor::Exception exp) {
        cerr << "Open error!";
        return 2;
    }

    int preys_start_sum = 0;
    for(int i=0; i< preys.size(); i++){
        preys_start_sum += preys[i]->get_starter_num();
    }

    cout << "Starting state: " << endl;
    printState(preys,predators);

    //endless for, break on condition
    for(int round=1;;round++){
        int preys_curr_sum = 0;

        cout <<"\n"<< round << "." << "Round: " << endl;

        //raise preys num, breed predators
        for(auto x: preys){
            x->raise_num(round);
        }
        for(auto x: predators){
            if(round % 8 == 0){
                x->breeding();
            }
        }

        cout << "\nAfter preys raise, before attack: " << endl;
        printState(preys,predators);

        //attack
        predators[rand()%predators.size()]->hunt(*preys[rand()%preys.size()]);

        cout << "\nAfter attack: " << endl;
        printState(preys,predators);

        //check end conditions
        for(auto x : preys){
            preys_curr_sum += x->get_num();
        }
        if(preys_start_sum*4 < preys_curr_sum){
            break;
        }
        if(preys_curr_sum <= 0){
            break;
        }
    }

    //memory deallocation
    for(auto x : preys){
        delete x;
    }
    for(auto x : predators){
        delete x;
    }

    return 0;
}
