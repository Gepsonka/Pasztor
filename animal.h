#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

using namespace std;

class Animal {
public:
    Animal(string nick, int num_animal);
    int get_num() const {return num_of_animal;}
    int set_num(int a){
        num_of_animal=a;
        return num_of_animal;
    }
    int get_starter_num() const {
        return starter_num;
    }

    string get_nickname(){return nickname;}
    friend istream& operator>>(istream& is,Animal& an);
    friend ostream& operator<<(ostream& os,const Animal& an);

protected:
    int num_of_animal;
    string nickname;
    int starter_num;
};


class Prey : public Animal{
public:
    using Animal::Animal;
    virtual ~Prey(){}
    virtual void getting_eaten(int predator_colony_num)=0;
    virtual void check_num()=0;
    virtual void raise_num()=0;


};

class Predators : public Animal{
public:
    using Animal::Animal;
    virtual ~Predators(){}
    friend istream& operator>>(istream& is, Animal& an);
    virtual void hunt(Prey& colony)=0;
    int check_not_enough_prey(int num_of_prey);
    virtual void breeding()=0;

};


class Lemming : public Prey {
public:
    using Prey::Prey;
    void getting_eaten(int predator_colony_num) override;
    void raise_num() override;
    void check_num() override;

};


class Rabbit : public Prey {
public:
    using Prey::Prey;
    void getting_eaten(int predator_colony_num) override;
    void check_num() override;
    void raise_num() override;

};

class Hamster : public Prey {
public:
    using Prey::Prey;
    void getting_eaten(int predator_colony_num) override;
    void check_num() override;
    void raise_num() override;

};


class SnowOwl : public Predators {
public:
    using Predators::Predators;
    void hunt(Prey& colony) override;
    void breeding() override;
};


class Wolf : public Predators {
public:
    using Predators::Predators;
    void hunt(Prey& colony) override;
    void breeding() override;
};


class ArticFox : public Predators {
public:
    using Predators::Predators;
    void hunt(Prey& colony) override;
    void breeding() override;
};



#endif // ANIMAL_H
