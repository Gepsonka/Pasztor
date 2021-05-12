#include "animal.h"
#include <iostream>

using namespace std;

istream& operator>>(istream& is,Animal& an){
    is>>an.nickname>>an.num_of_animal;
    return is;
}

ostream& operator<<(ostream& os,const Animal& an){
    os<<an.nickname<<": "<<an.num_of_animal<<endl;
    return os;
}

Animal::Animal(string nick, int num_animal):num_of_animal(num_animal),starter_num(num_animal),nickname(nick)
{}


void Lemming::check_num(){
    if (get_num()>200){
        set_num(30);
    }
}


void Lemming::getting_eaten(int predator_colony_num){
    set_num(get_num()-(4*predator_colony_num));
    check_num();

}

void Lemming::raise_num(){
    set_num(get_num()*2);
}


void Rabbit::getting_eaten(int predator_colony_num){
    set_num(get_num()-predator_colony_num*2);
    check_num();
}

void Rabbit::check_num(){
    if (get_num()>100){
        set_num(20);
    }
}



void Rabbit::raise_num(){
    set_num(int(get_num()*1.5));
}


void Hamster::getting_eaten(int predator_colony_num){
    set_num(get_num()-predator_colony_num*2);
    check_num();
}

void Hamster::check_num(){
    if (get_num()>200){
        set_num(40);
    }
}

void Hamster::raise_num(){
    set_num(get_num()*2);
}

int Predators::check_not_enough_prey(int num_of_prey){
    int original=num_of_animal;
    if (num_of_prey<num_of_animal){
        set_num(get_num()-(int)(get_num()/4));
    }
    return original;
}

void SnowOwl::hunt(Prey& colony){
    colony.getting_eaten(check_not_enough_prey(colony.get_num()));

}

void SnowOwl::breeding(){
    set_num(get_num()+int(get_num()/4));
}


void Wolf::hunt(Prey& colony){
    colony.getting_eaten(check_not_enough_prey(colony.get_num()));

}

void Wolf::breeding(){
    set_num(get_num()+3*int(get_num()/4));
}


void ArticFox::hunt(Prey& colony){
    colony.getting_eaten(check_not_enough_prey(colony.get_num()));

}

void ArticFox::breeding(){
    set_num(get_num()+2*int(get_num()/4));
}


