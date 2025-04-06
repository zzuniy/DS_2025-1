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
    bool empty(); //스택이 비었는지 확인 현재 코드에서는 필요 없지만 후에 필요할 수 있음. EOS를 쓰지 않을 경우
    char top_element(); //스택의 top원소를 스리슬쩍 봐보는 함수. 우선순위 비교를 위해 필요함
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

bool op_stack::empty(){
    return (top ==0); //empty일 경우를 판별 ==
}

char op_stack::top_element(){
    return(s[top-1]); //현재 탑 원소를 return
}

bool is_operand(char ch){
    if((ch == '(') || (ch == ')') || (ch == '+') || (ch == '-') || (ch == '*')|| (ch == '/') || (ch == '%') || (ch == '$')) 
        return false; //연산자면 flase

    else 
        return true; //일반 문자면 true
}

int get_precedence(char op)
{
    if((op == '$') || (op == '('))
        return(0); //우선순위 최하
    if((op == '+') || (op == '-'))
        return(1); // 얘넨 중간
    if((op =='*') || (op == '/') || (op == '%'))
        return(2); // 너네가 최고
    return(-1); // 그 이외 미만잡
}
int main(){
    string input, output; //input output 두 개의 문자열 선언 
    op_stack stack1; // object선언
        cout << "Input an infix expression to convert: "; //여기에 문자를 입력하세요 프린트
        cin >> input; //문자열 입력받기
        input += EOS; //맨끝에 끝을 알리는 문자 추가
        stack1.push(EOS); //stack끝을 알기 위해 $추가
        for(int i=0; i < input.size(); i++){ //문자열 size만틈 loop
            if(is_operand(input[i])){ //만약 연산자가 아니면
            output += input[i];//output에 문자 추가
            
            }else if(input[i] == '(') { //여는 괄호라면
                    stack1.push(input[i]); //stack에 문자 넣기
            }
            else if (input[i] == ')') { //닫는 괄호라면
                while (stack1.top_element() != '(') //탑이 여는 괄호가 될 때까지
                output += stack1.pop(); //원소를 꺼내서 output애 넣기
                stack1.pop();//열린 괄호 재거
            }
            else { 
                while (get_precedence(stack1.top_element()) >= get_precedence(input[i])&&(stack1.top_element() != EOS)) //stack의 안쪽 원소의 우선순위가 새로운 우선순위보다 높거나 같을 경우 , EOS는 제외
                    output += stack1.pop(); //output에 안쪽 원소 넣기
                stack1.push(input[i]); // 현재 원소 stack에 넣기
            } 
        }
        while (stack1.top_element() != EOS) { //EOS가 아닐때까지
            output += stack1.pop(); // output에 스택 안에 있는 원소 넣기
        }
        cout << output << endl; //전체 출력
        
}
