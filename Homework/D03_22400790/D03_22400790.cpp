# include <iostream>
#define SIZE 100 // 100을 SIZE로 매크로 지정
#define EOS '$' // $(0)문자를 EOS로 매크로 지정
using namespace std;// 기본 

class op_stack{ //클래스 선언
    char s[SIZE]; // s[100]의 문자 선언
    int top; // 탑 변수 선언
public : //퍼블릭 변수
    op_stack(); // constructor
    void push(char x); // stack에 push하는 함수
    char pop(); //stack에서 pop하는 함수

    char top_element(); //스택의 top원소를 스리슬쩍 봐보는 함수. 우선순위 비교를 위해 필요함
    bool isOpen(char ch);
    bool isClose(char ch);
    char match(int num);
};

op_stack::op_stack(){ //top값을 초기화 하는 constructor
    top = 0;
}

void op_stack::push(char x){ 
    s[top] = x; //x를 s[맨 위]에 넣기
    top ++; //맨 위 index 증가(넣을 곳)
}

char op_stack::pop(){
    top--; //꺼낼곳 인덱스
    return(s[top]); //맨 위 element를 return
}
char op_stack::top_element(){
    return(s[top-1]); //현재 탑 원소를 return
}

bool is_pare(char ch){
    if((ch == '(') || (ch == ')') || (ch == '[') || (ch == ']') || (ch == '{')|| (ch == '}')) 
        return true; 

    else 
        return false;
}

bool op_stack::isOpen(char ch){
    if((ch =='(')||(ch =='[')||(ch =='{'))
    return true;
    else 
    return false;
}
bool op_stack::isClose(char ch){
    if((ch ==')')||(ch ==']')||(ch =='}'))
    return true;
    else 
    return false;
}
int get_precedence(char op)
{
    if((op == '(')||(op == ')'))
        return(0); 
    if((op == '{')||(op == '}'))
        return(1); 
    if((op =='[')||(op == ']'))
        return(2); 
    return(-1);
}

char op_stack::match(int num){

        if(num ==0)
        return ')';
        else if(num ==1)
        return '}';
        else if(num ==2)
        return ']';

        return '?';
    }

int main(){
    string input, output; //input output 두 개의 문자열 선언 
    op_stack stack1; // object선언
        cout << "Input an infix expression to convert: "; //여기에 문자를 입력하세요 프린트
        cin >> input; //문자열 입력받기
        input += EOS; //맨끝에 끝을 알리는 문자 추가
        stack1.push(EOS); //stack끝을 알기 위해 $추가

        for(int i=0; i < input.size(); i++){
                if(is_pare(input[i])){
                    if(stack1.isOpen(input[i])){ //stack의 안쪽 원소의 우선순위가 새로운 우선순위보다 높거나 같을 경우 , EOS는 제외
                        
                        stack1.push(input[i]); // 현재 원소 stack에 넣기
                    }

                    if(stack1.isClose(input[i])){
                        if (get_precedence(stack1.top_element()) == get_precedence(input[i]) && (stack1.top_element() != EOS)){
                       
                        stack1.pop();
                        }
                        else if (get_precedence(stack1.top_element()) != get_precedence(input[i])){
                            if(input[i+1]!=EOS){
                                cout<<"Error: mis-matched parenthesis,'"<< stack1.match(get_precedence(stack1.top_element()))<<"' is expected"<<endl;
                                exit(1);
                            }
                            if(input[i+1]==EOS ){
                                stack1.push(input[i]);
                 
                            } 
                        }
                    }
                }
        }
      
        if( stack1.top_element()!=EOS&& stack1.isClose(stack1.top_element())){
            cout<<"An extra patra parenthesis '"<<stack1.top_element()<<"' is fountd. "<<endl;
            exit(1);
        }
        else if( stack1.top_element()!=EOS&& stack1.isOpen(stack1.top_element())){ //여기 엘이프로 가야지
            cout<<"Error: mis-matched parenthesis,'"<< stack1.match(get_precedence(stack1.top_element()))<<"' is expected"<<endl;
             exit(1);
        }
        cout << "It's a normal expression" << endl;
    }
