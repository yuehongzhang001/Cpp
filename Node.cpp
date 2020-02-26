include <iostream>
using namespace std;
class Node{
public:
    class out_of_range{
        string str;
    public:
        out_of_range(string s):str{s}{cout<<str<<endl;}
    };
    Node* left;
    Node* right;
    int data;
    int size;
    Node()= default;
    Node(int n,Node* ln= nullptr):data{n},left{ln},right{nullptr},size{1}{}
    int get_data()const{ return data;}
    int operator[](int i){
        if(i>=size)
            throw out_of_range{"out of range"};
        if(i==0){
            return this->data;
        } else{
            return (*right)[i-1];
        }
    }
    void add_int(int n){
        size++;
        if(right== nullptr){
            right=new Node{n,this};
        } else{
            (*right).add_int(n);
        }
    }
    ~Node(){
        delete right;
        cout<<"<right deleted!>"<<endl;
    }

};
int main(){
//    cell * cp=new cell;
//    char * mp= reinterpret_cast<char*>(cp);
//    cout<<*mp<<endl;
//    int* ip= reinterpret_cast<int*>(mp);
//    ip++;
//    cout<<(*ip);
//    delete cp;
    Node node(2);
    node.add_int(5);
    node.add_int(10);
    node.add_int(15);
    cout<<node[0]<<endl;
    cout<<node[1]<<endl;
    cout<<node[2]<<endl;
    cout<<node[3]<<endl;


    return 0;
}