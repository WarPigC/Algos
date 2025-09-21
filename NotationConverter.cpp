#include <iostream>
#include <algorithm>
#include <string>
#include "StackImplementation.cpp"

// precedence table getter function
int getPrec(char& c){
    switch(c){
        case '^': return 4;
        case '*': return 3;
        case '/': return 3;
        case '+': return 2;
        case '-': return 2;
        case '(': return 0;
        default: return -1;
    }
}

bool isValidOperand(char& c){
    return ((c >= 48) && (c <= 57)) || ((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122));
}

bool isValidOperator(char& c){
    return (((c >= 40) && (c <= 45)) || (c == 94) || (c == 47));
}

void popUntilCond(stack& stk,std::string& str,char& c){
// pushes stack elements to postfix UNTIL stk.top() has lower prec or stack is empty
    
    while ((getPrec(stk.getTop()) > getPrec(c)) && !(stk.isEmpty())){
        str += stk.getTop();
        stk.pop();
    }
    stk.push(c);
}

std::string InfixToPostfix(std::string& str){
    std::string postfix{};
    stack stk{1};

    for(int i = 0; i < str.size(); ++i){
        char& c = str[i];
        
        if (isValidOperand(c)) postfix += c;
        
        else if (isValidOperator(c)){

            if (c == '('){
                stk.push(c);
            }

            else if (c == ')'){            
                while(stk.getTop() != '('){
                    postfix += stk.getTop();
                    stk.pop();
                }
                stk.pop();
            }

            else if (getPrec(c) > getPrec(stk.getTop())){     
                stk.push(c);
            }

            else if (getPrec(c) < getPrec(stk.getTop())){     
                popUntilCond(stk,postfix,c);    
            }

            else if (getPrec(c) == getPrec(stk.getTop())){
                if (stk.getTop() == '^'){
                    stk.push(c);
                }
                else{                           
                    popUntilCond(stk,postfix,c);
                }
            }
        } 
        else{
            std::cout << "INVALID OPERATOR\n";
            break;
        }

    }   // iterating loop
    
    while(stk.isEmpty() == false){
        if (stk.getTop() != ')'){
            postfix += stk.getTop();
        }
        stk.pop();
    }

    return postfix;
}


std::string InfixToPrefix(std::string& str){
    std::string prefix{};
    stack stk{1};

    for (int i = 0; i < str.size(); ++i){
        char& c = str[str.size() - 1 - i];
 
        if (isValidOperand(c)){
            prefix += c;
        }

        else if (isValidOperator(c)){

            if (c == ')'){
                stk.push(c);
            }

            else if (c == '('){
                while (stk.getTop() != ')'){
                    prefix += stk.getTop();
                    stk.pop();
                }
                stk.pop();        
            }
            
            else if (getPrec(c) > getPrec(stk.getTop())){
                stk.push(c);
            }

            else if (getPrec(c) < getPrec(stk.getTop())){

                while(getPrec(stk.getTop()) > getPrec(c) && !(stk.isEmpty())){
                    prefix += stk.getTop();
                    stk.pop();
                }
                stk.push(c);
            }
            
            else if (getPrec(c) == getPrec(stk.getTop())){
                if (stk.getTop() == '^'){ 
                    while(getPrec(stk.getTop()) > getPrec(c) && !(stk.isEmpty())){
                        prefix += stk.getTop();
                        stk.pop();
                    }
                    stk.push(c);
                }
                else{
                    stk.push(c);
                }
            }
        }
    }   // loop
    
    while(stk.isEmpty() == false){
        if (stk.getTop() != '('){
            prefix += stk.getTop();
        }
        stk.pop();
    }

    std::reverse(prefix.begin(),prefix.end());

    return prefix;
}


std::string PostfixToInfix(std::string postfix){
    StringStack stk{2};
    
    for (int i = 0; i < postfix.size(); ++i){
        char& c = postfix[i];

        if (isValidOperand(c)){
            std::string temp{};
            stk.push((temp+c));
        }

        if (isValidOperator(c)){
            if(stk.isEmpty() == false){
                std::string s1 {stk.getTop()};
                stk.pop();
                std::string s2 {stk.getTop()};
                stk.pop();
                stk.push("("+s2+c+s1+")");
            }
        }
    }

    return stk.getTop();
}


std::string PrefixToInfix(std::string prefix){
    StringStack stk{2};
    
    for (int i = 0; i < prefix.size(); ++i){
        char& c = prefix[prefix.size() - 1 - i];

        if (isValidOperand(c)){
            std::string temp{};
            stk.push((temp+c));
        }

        else if (isValidOperator(c)){
            if(stk.isEmpty() == false){
                std::string s1 {stk.getTop()};
                stk.pop();
                std::string s2 {stk.getTop()};
                stk.pop();
                stk.push("("+s1+c+s2+")");
            }
        }
        else{
            std::cout << "INVALID OPERATOR\n";
            return "";
        }
    }

    return stk.getTop();
}



std::string PostfixToPrefix(std::string postfix){
    std::string ans = PostfixToInfix(postfix);
    return InfixToPrefix(ans);
}

std::string PrefixToPostfix(std::string prefix){
    std::string ans = PrefixToInfix(prefix);
    return InfixToPostfix(ans);
}

void display(){
    std::cout << "\n1: infix\n";
    std::cout << "2: postfix\n";
    std::cout << "3: prefix\n";
}


int main(){ 
    while(true){
        std::string input{"XX"}, inp{};
        display();
        std::cout << "Enter notation type: ";
        std::cin >> input[0];
        
        display();
        std::cout << "convert to?: ";
        std::cin >> input[1];
        
        std::cout << "\ninp: ";
        std::cin >> inp;

        if (input == "12"){
            std::cout << "\nAnswer: " << InfixToPostfix(inp) << '\n';
            break;
        }
        else if (input == "13"){
            std::cout << "\nAnswer: " << InfixToPrefix(inp) << '\n';
            break;
        }
        else if (input == "21"){
            std::cout << "\nAnswer: " << PostfixToInfix(inp) << '\n';
            break;
        }
        else if (input == "23"){
            std::cout << "\nAnswer: " << PostfixToPrefix(inp) << '\n';
            break;
        }
        else if (input == "31"){
            std::cout << "\nAnswer: " << PrefixToInfix(inp) << '\n';
            break;
        }
        else if (input == "32"){
            std::cout << "\nAnswer: " << PrefixToPostfix(inp) << '\n';
            break;
        }
        else{
            std::cout << "INVALID INPUT\n";
            continue;
        }
    }
}
