#include <iostream>
#include <string>

// Linked List implementation and std::list stuff


struct Node{
    Node* next;
    std::string data;

    Node(std::string d) :next{nullptr}, data {d} {}
};


class LinkedList{
    
    Node* head;

    public:
        LinkedList(){
            head = nullptr;
        }

        void Display() const {
            Node *temp = head;

            while(temp != nullptr){
                std::cout << '|' << temp->data << '|' << " -> ";
                temp = temp->next;
            }
            std::cout << "NULL\n";
        }

        void Insert(std::string d, int position = -1){
    
            Node* New_Node = new Node(d);
            Node *temp = head;

            if (head == nullptr){
                head = New_Node;
                return;
            }
            if (position == -1){
                // append
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = New_Node;
                return;
            }
            else{
                for(int i = 0; i <= position && temp->next != nullptr ; ++i){
                    temp = temp->next;
                }
                if (temp == nullptr) {
                    std::cout << "INVALID POS\n";
                    return;
                }
                else temp->next = New_Node;
            }
        }

        void Delete(int pos){
        
            Node* temp = head;
            if (temp == nullptr){
                std::cout << "EMPTY\n";
                return;
            }
            else if(pos == 0){
                Node* t = head;
                head = temp->next;
                delete t;
            }
            else{
                for(int i = 0; i < pos - 1 && temp->next != nullptr; ++i){
                    temp = temp->next;
                }
                if(temp->next == nullptr){
                    std::cout << "Invalid Position\n";
                }
                else{
                    Node* t = temp->next; 
                    temp->next = t->next;
                    delete t;
                }
            }
            
        }
};


int main(){
    LinkedList list;

    list.Insert("first");
    list.Insert("second");
    list.Insert("third");
    list.Insert("fourth");
    list.Delete(2);

    list.Display();
}
