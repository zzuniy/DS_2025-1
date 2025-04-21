#include <iostream>
using namespace std;

// queue의 개념
// Isert: 한 개 원소를 저장 (한쪽 끝 rear)
// Delete: 한 개 원소를 취함(다른 끝 front)
#define SIZE 100
class Q{
public:
    int data[SIZE];
    int rear, front;
    Q();
    void insert(int input_data);
    int delete_data();
    bool isFull();
    bool isEmpty();
};
    Q::Q(){
        rear = 0;
        front=0;
    }
    void Q::insert(int input_data){
        if(!isFull()){
            data[rear] = input_data;
            rear = (rear+1)%SIZE;
        }
     
    }
    int Q::delete_data(){
        int tmp;
        if(!isEmpty()){
            tmp = data[front];
            data[front] = 0;
            front = (front+1)%SIZE;
            return tmp;
        }
        else
        exit(0);
    }
    bool Q::isFull(){
        if((rear+1)%SIZE==front)
            return true;

        else
            return false;
    }
    bool Q::isEmpty(){
        if(rear==front)
            return true;
        else 
             return false;
    }

    int main(){
        Q q;
        int t;

        q.insert(1);
        q.insert(2);
        q.insert(3);

        t = q.delete_data();
        t = q.delete_data();

        q.insert(4);
        q.insert(5);

        while(!q.isEmpty()){
            t = q.delete_data();
            cout<<t<<endl;
        }

        return 0;

    }