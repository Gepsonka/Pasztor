#include "animal.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;


int main(int argc,char *argv[]){

    ifstream pasztor_file;
    pasztor_file.open(argv[1]);
    cout<<argv[1]<<endl;
    if (pasztor_file.is_open()){
        cout<<"File opened successfully!"<<endl;
        
    }
    else {
        cout<<"error\n";
        pasztor_file.close();
    }


    vector<Prey*> prey_colonies;
    vector<Predators*> predator_colonies;

    Lemming lemming(23,"coco");
    cout<<lemming<<endl;

    for(int i=1;;i++){

    }


    

    for (auto n : prey_colonies){
        delete n;
    }

    for(auto n : predator_colonies){
        delete n;
    }
    

} 