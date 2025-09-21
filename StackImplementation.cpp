#include <vector>
#include <iostream>
#include <string>

class stack{
    private:
        std::vector<char> v;
        int top;
        int size;

    public:

        stack(int size = 0){
            v = std::vector<char>();
            this->size = size;
            top = -1;
        }

        void push(char element){
            ++top;
            v.push_back(element);
            //if (top < size){
                //++top;
                //v.push_back(element);
            //}
            //else{
                //std::cout << "ERROR\n" << "Buffer Overflow\n" << "Top currently at: " << top <<'\n';
            //}
        }


        void pop(){
            if (top == -1){
                std::cout << "ERROR\n" << "Buffer Underflow\n" << "Top currently at: " << top << '\n';
            }
            else{
                v.pop_back();
                --top;
            }
        }

        char& getTop(){
            if (top == -1){
                return *(new char(-1));
            }
            else return v[top];
        }

        bool isEmpty(){
            return (top == -1)? true : false;
        }
};


class StringStack{
    private:
        std::vector<std::string> v;
        int top;
        int size;

    public:
        StringStack(int Size){
            v = std::vector<std::string>();
            this->size = Size;
            top = -1;
        }

        void push(std::string element){
            ++top;
            v.push_back(element);
            //if (top < size){
                //++top;
                //v.push_back(element);
            //}
            //else{
                //std::cout << "ERROR\n" << "Buffer Overflow\n" << "Top currently at: " << top <<'\n';
            //}
        }
        
        void pop(){
            if (top == -1){
                std::cout << "ERROR\n" << "Buffer Underflow\n" << "Top currently at: " << top << '\n';
            }
            else{
                v.pop_back();
                --top;
            }
        }

        std::string& getTop(){
            if (top == -1){
                return *(new std::string{-1});
            }
            else return v[top];
        }

        bool isEmpty(){
            return (top == -1)? true : false;
        }
};
