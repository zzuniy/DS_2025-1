#include <iostream>
#include <string>
using namespace std;

// 이 예제는 my_list 클래스와 node 클래스가 이미 정의되어 있다고 가정합니다.

class node{
    public:
    string name;
    float score;
    node *link;
    node();
    void set_data(string input_name, double num);
};
node::node(){
    name="";
    score=0;
}

void node::set_data(string input_name, double num){
    name = input_name;
    score = num;
    
}

class my_list{
    public:
    node *head=NULL;
    node *tail=NULL;
    
    // void add_to_tail(node t);
    void add_to_head(node t);
    int num_nodes();
    double score_sum();

    node delete_from_head();
    int remove_a_node(string name);
    double get_score(string name);

};
    // void my_list::add_to_tail(node t){
    //     node *p;
    //     p = new node;
    //     (*p) = t;
    //     p -> link = NULL;
    //     if(tail != NULL)
    //     tail -> link = p;

    //     else 
    //         head = p;
    //     tail = p;
    // }
    void my_list::add_to_head(node t){
        node *p;
        p = new node;
        (*p) = t;
       p -> link =head;
       head = p;
    //    if(tail == NULL)
    //    tail = p;
    }

    int my_list::num_nodes(){
        node *p ;
        int count=0;
        for(p = head; p!=NULL; p=p->link){
            count++;
        }
        return count;
    }
    double my_list::score_sum(){
        double sum=0; 
        node *p ;
        for(p = head; p!=NULL; p=p->link){
            sum += p->score;
        }
        return sum;
    }

    node my_list::delete_from_head(){
        node *p  = head;
        node tmp= *head;
        head = head->link;
        delete p;
        // if(head == NULL)
        //     tail= NULL;
        return tmp;
    }
   int my_list::remove_a_node(string name){
        node *target;
        node *prev;
        prev = NULL;
        target = head;
  
        while(target != NULL&&target -> name != name){
            prev = target;
            target = target -> link;

        }
        
        if(target ==NULL)
        return 0;

        if(prev == NULL){
            head = target -> link;
        }
        else{
            prev->link = target->link;
        }
        delete target;
        return 1;

    }
    double my_list::get_score(string name){
        node *target;
        target = head;
        
        while(target !=NULL&&target -> name != name){
            target = target->link;
        }
        if(target ==NULL)
        return -1;
        else
        return target -> score;
    }


int main() {
    my_list a;
    node tmp;

    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);

    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp); // head 위치로 2개의 원소 추가

    cout << a.num_nodes() << " : " << a.score_sum() << "\n"; // 1단계 점검

    tmp.set_data("Park", 91.3);
    // a.add_to_tail(tmp); // tail 위치로 1개의 원소 추가

    cout << a.num_nodes() << " : " << a.score_sum() << "\n"; // 2단계 점검

    tmp = a.delete_from_head();
    cout << tmp.name << " is deleted.\n"; // 3단계 점검

    tmp.set_data("Choi", 85.1);
    // a.add_to_tail(tmp);

    tmp.set_data("Ryu", 94.3);
    a.add_to_head(tmp); // 2개의 원소 추가

    cout << a.num_nodes() << " : " << a.score_sum() << "\n";

    cout << "Park’s score : " << a.get_score("Park") << "\n"; // 4단계 점검

    if (a.remove_a_node("Kim") == 1)
        cout << "Kim is deleted from the list.\n"; // 5단계 점검

    cout << a.num_nodes() << " : " << a.score_sum() << "\n"; // 최종 점검

    return 0;
}
