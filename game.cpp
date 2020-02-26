#include <iostream>
#include <vector>
#include <map>


using namespace std;
/*
 *1|end|
 *9|x  |
 *8|   |
 *7|xx |
 *6|   |
 *5| xx|
 *4|   |
 *3|xx |
 *2|   |
 *1| xx|
 *0| c |
 * 01234
 */



struct Position{
    int x;
    int y;
};


class Charactor{
public:
    Position cp;
};

class Object{
public:
    Position op;
};

class Border{
public:
    Position bp;
};

enum class Move{
    Left,Right,UP,Down
};
enum class Type{
    CHAR,OBJ,BORDER
};

class Map{
public:
    std::map<Position,Type> ps;
    bool find(Position p){
        map<Position,Type>::iterator iter;
        for(iter=ps.begin();iter!=ps.end();iter++){
            int a=iter->first.x;
            int b=iter->first.y;
            if (a==p.x && b==p.y) return true;
        }
        return false;
    }
};


class Game{
    Charactor c;
    vector<Object> obs;
    vector<Border> bords;

public:
    Map map;
    Game(){
        c=Charactor();
        c.cp = {1,2};
        //create objects and give them position
        initializeObjects();
        initializeBorders();
        //store all the values of positions in map
        map.ps[c.cp]=Type::CHAR;
        for(Object ob: obs){
            map.ps[ob.op]=Type::OBJ;
        }
        for(Border bd: bords){
            map.ps[bd.bp]=Type ::BORDER;
        }
    }
    bool moveCharactor(Move m){
        Position cp = c.cp;
        Position moveTo = cp;
        switch (m){
            case Move::Left: moveTo.x -= 1;
                break;
            case Move::Right: moveTo.x += 1;
                break;
            case Move::UP: moveTo.y+=1;
                break;
            case Move::Down: moveTo.y-=1;
                break;
        }
        //check if moveTo avaible?
        if (isAvailable(moveTo)){
            map.ps.erase(c.cp);
            c.cp = moveTo;
            map.ps[moveTo]=Type ::CHAR;
            return true;
        } else
            return false;
    };
    bool youWin(){
        return c.cp.y>9;
    }
    void initializeObjects();
    void initializeBorders();
    bool isAvailable(Position p);
};



class ViewController{
    Game game;
public:
    ViewController(){
        game = Game();
        while (!game.youWin()){
            Move move = getInput();
            game.moveCharactor(move);
            show(game.map);
        }
        cout<<"you win!"<<endl;
    }
    Move getInput(){
        cout<<"Your move: ";
        string input="";
        cin>>input;
        if(input == "w") return Move::UP;
        else if(input=="a") return Move::Left;
        else if(input=="s") return Move ::Down;
        else if(input=="d") return Move ::Right;
        else {
            cout<<"invalid move"<<endl;
            getInput();
        }
    };
    void show(Map& map){
        Position p;
        for(int i=0;i<5;i++){
            for(int j=0;j<12;j++){
                p={i,j};
                if (map.find(p)){
                    switch (map.ps[p]){
                        case Type::CHAR: cout<<'C';
                            break;
                        case Type::BORDER: cout<<'|';
                            break;
                        case Type::OBJ : cout<<'*';
                            break;
                    }
                } else
                    cout<<' ';
            }
            cout<<endl;
        }
    };
};
void Game::initializeObjects() {
    obs=vector<Object>(11);
    obs[0].op = {2,1};
    obs[1].op = {3,1};
    obs[4].op = {1,3};
    obs[5].op = {2,3};
    obs[6].op = {2,5};
    obs[7].op = {3,5};
    obs[8].op = {1,7};
    obs[9].op = {2,7};
    obs[10].op = {1,9};
}

void Game::initializeBorders(){
    bords = vector<Border>(20);
    bords[0].bp = {0,0};
    bords[1].bp = {4,0};
    bords[2].bp = {0,1};
    bords[3].bp = {4,1};
    bords[4].bp = {0,2};
    bords[5].bp = {4,2};
    bords[6].bp = {0,3};
    bords[7].bp = {4,3};
    bords[8].bp = {0,4};
    bords[9].bp = {4,4};
    bords[10].bp = {0,5};
    bords[11].bp = {4,5};
    bords[12].bp = {0,6};
    bords[13].bp = {4,6};
    bords[14].bp = {0,7};
    bords[15].bp = {4,7};
    bords[16].bp = {0,8};
    bords[17].bp = {4,8};
    bords[18].bp = {0,9};
    bords[19].bp = {4,9};
    bords[20].bp = {0,10};
    bords[21].bp = {4,10};

}

bool Game::isAvailable(Position p){
    return !map.find(p);
}

int main(){
    ViewController v=ViewController();
    return 0;
}

//
// Created by yuehong zhang on 2019-08-09.
//

