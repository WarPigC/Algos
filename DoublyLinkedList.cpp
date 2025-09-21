#include <iostream>

struct Node{
    int val;
    Node *next, *previous;

    Node(int v)
        :val{v},
        next{nullptr},
        previous{nullptr}
    {}
};

class Doubly{
    Node *head, *tail;
    int Size;
public:
    Doubly() :head{nullptr}, tail{nullptr}, Size{0} {}

    void Insert(int v, int pos = 0){
        if (!(head && tail)){
            Node* temp = new Node(v);
            tail = temp;
            head = temp;
        }
        else if (pos == Size - 1){
            Node* temp = new Node(v);
            tail->next = temp;
            temp->previous = tail;
            tail = temp;
        }
        else if (pos >= 0){
            if (pos > Size / 2){
                // tail
            }
            else{
                // head
            }
        }
    }
    
    void Delete(int v, int pos = 0){

    }

    void display(){

    }

    // size 
    int size(){ return Size; }

};

int main(){

}
