#include <iostream>
#include <thread>
#include <time.h>
#include <exception>


using namespace std;


class Game{
public:
    class Event{
    };
    void BeginPlay(){
        for(int i=0;i<10;i++){
            Tick();
        }

    }
    void Tick(){
        cout<<"<R "<<Round++<<">";
        string input="";
        cin>>input;
        if(input=="stop"){
            Event e;
            eptr=&e;
        }

        else{
            cout<<"moving";
        }
        if(check_event()){
            OnEventOccur();
        };
        cout<<endl;

    }
    bool check_event(){
        return eptr!=nullptr;
    }
    void OnEventOccur(){
        cout<<"stopped";
    };

private:
    int Round{};
    Event* eptr= nullptr;
};


int main(){
    Game g1;
    g1.BeginPlay();

    return 0;
}