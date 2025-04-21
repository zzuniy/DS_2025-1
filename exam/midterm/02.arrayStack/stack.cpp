// Array를 사용한 stack 구현 -> push pop 내용 파악 및 응용
#include <iostream>
using namespace std;

#define SIZE 100
class Stack{
    public:
    int data[SIZE];
    int top;;
    Stack();
    void push(int input_data);
    int pop();
    bool is_empty();
    bool is_full();
    
};
    Stack::Stack(){
        top=0;
    }

    void Stack::push(int input_data){
        if(!is_full()){
            data[top] = input_data;
             top++;
        }
        else exit(0);
    }

    int Stack::pop(){
        if(!is_empty()){
            top--;
            return data[top];
        }
        else exit(0);
    }

    bool Stack::is_empty(){
        if(data[top]==0)
            return true;

        else 
            return false;
    }
    bool Stack::is_full(){
        if(top == SIZE-1)
            return true;

        else 
            return false;
    }

    int main(){
        Stack st;
        int n;

        st.push(3);
        n = st.pop();
        cout<<n;
        
    }