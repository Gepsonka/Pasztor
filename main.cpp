#include "Animal.h"
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

int main(int argc,char *argv[]){

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
                case 'h':
                    break;
                default:

            }
        }
<<<<<<< Updated upstream
        for(int i=0; i< preys.size(); i++){
            cout << preys[i]->get_nickname() << endl;
        }
=======
        /*for(int i=0; i< preys.size(); i++){
            cout << preys[i]->get_nickname() << endl;            
        }
        for(int i=0; i< preys.size(); i++){
            cout << predators[i]->get_nickname() << endl;            
        }*/
        
>>>>>>> Stashed changes

    }
    catch(Enor::Exception exp) {
        cerr << "Open error!";
        return 2;
    }
}
