#include <iostream>
#include <thread>
#include <time.h>
#include <exception>


using namespace std;

class NPC{
    string name="";
public:
    NPC(string name):name{name}{}
    void walk(){
        cout<<"NPC "<<name<<" is walking"<<endl;
    }
    void fly(){
        cout<<"NPC "<<name<<" is flying"<<endl;
    }
    string getName(){
        return name;
    }
};

//level
NPC npc1=NPC("1");
NPC npc2=NPC("2");

//controll level
class Controller{
    NPC& npc01 = npc1;
    NPC& npc02 = npc2;
public:
    void walk(string name){
        NPC& n = find(name);
        n.walk();
    }

    void fly(string name){
        NPC& n = find(name);
        n.fly();
    }

    NPC& find(string name){
        if(name == npc1.getName())
            return npc1;
        else if(name == npc2.getName())
            return npc2;
    }
};
int main(){
    Controller controller{};
    controller.walk("1");
    controller.fly("2");
    return 0;
}
//
// Created by yuehong zhang on 2019-08-09.
//

