#include "animal.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

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


    Lemming lemming;
    Rabbit rabbit;
    Hamster hamster;

    SnowOwl snowowl;
    Wolf wolf;
    ArticFox articfox;



    for (int i=0;i<100000;i++){


    }



    
    

} 