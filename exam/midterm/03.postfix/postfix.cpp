#include <iostream>
using namespace std;

#define SIZE 100
class Conversion{
    public:
    char data[SIZE];

    int top;
    Conversion();
    void push(char input_data);
    char pop();
    bool is_empty();
    bool is_full();

    bool is_operand(char input_char);
    int priority(char input_char);
};

Conversion::Conversion(){
    top =0;
}

void Conversion::push(char input_data){
    if(!is_full()){
        data[top] = input_data;
        top++;
    }
       
    else
        exit(0);
}

char Conversion::pop(){
    if(!is_empty()){
        top--;
        return data[top];
    }
    else
        exit(0);
}

bool Conversion::is_empty(){
    if(top ==0)
        return true;
    else
        return false;
}
bool Conversion::is_full(){
    if(top == SIZE-1)
        return true;
    else
        return false;
}

bool Conversion::is_operand(char input_char){
    if (input_char == '(' || input_char == ')' || input_char == '*' || input_char == '/' ||
        input_char == '+' || input_char == '-' || input_char == '$' || input_char == '%')
        return false;
    else
        return true;
}

int Conversion::priority(char input_char){

    if(input_char =='('||input_char =='$')
    return 0;

    else if(input_char=='+'||input_char=='-')
    return 1;

    else if(input_char=='/'||input_char=='*'||input_char=='%')
    return 2;

    return -1;
}

int main(){
    Conversion conv;
    string user_input;
    string output;
    cin >> user_input;
    user_input += '$';

    for(int i=0; i<user_input.size(); i++){
        if(user_input[i]=='$'){
            conv.push(user_input[i]);
        }

        if(user_input[i]=='('){
            conv.push(user_input[i]);
        }
        
        else if(user_input[i] == ')'){    
            while (conv.data[conv.top - 1] != '(') {
                output += conv.pop();
            }
            conv.pop(); // '(' 버림
            continue;
        }

        else if(conv.is_operand(user_input[i])){
            output += user_input[i];
        }

        else if(!conv.is_operand(user_input[i])){
            while(conv.priority(conv.data[conv.top-1])>=conv.priority(user_input[i])&&(user_input[i]!=')')){
                output+=conv.pop();
            }
            conv.push(user_input[i]); //퍼시
        }
    }
    
    while (conv.data[conv.top - 1] != '$') {
        output += conv.pop();
    }
    cout<<output;
}