#include <iostream>
#include <string>

using namespace std;

#define   SUCCESS   1
#define   FAIL         0

class node {
public:
        string   name;
        double      score;
        node *link;
        void   set_data(string   s, double n);
};

void   node::set_data(string s, double n) {
           name = s;
           score = n;
}

class my_list {
        node   *head;
        node  *tail;
public:
        my_list();
        void add_to_head(node   t);
        void add_to_tail(node t);
        int remove_a_node(string tname);
        int num_nodes(); //node의 개수
        bool list_empty(); //empty확인
        void    insert_a_node(string tname, node t);
        void show_all_data();
};

my_list::my_list()
{
        head = NULL;
        tail = NULL;
}
bool my_list:: list_empty(){
    if(head == NULL)
    return true;

    else 
    return false;
}

void my_list::add_to_tail(node t){
    node *p;
    p = new node; 
    (*p) = t;
    p -> link = NULL;
  
    if(tail == NULL)
        head = p;
    else{
        tail->link = p;
    }
    tail =p;
}

int my_list::num_nodes(){
    int num =0; 
    node *p;
    for(p = head; p!=NULL; p = p->link){
        num ++;
    }
    return num;
}

void my_list::add_to_head(node t) {
    node *p;
    p = new node;
    (*p) = t;
    p -> link = head;
    head = p;

    if(tail == NULL)
        tail = p;
}

int my_list::remove_a_node(string tname)
{
    node *prev, *target;
    prev = NULL;
    target = head;
    while(target != NULL&&target -> name != tname){
        prev = target;
        target = target -> link;
    }
    if(target == NULL) //못찾았을 경우
    return FAIL;

    if(prev){ 
    prev -> link = target -> link;
    delete target;
    
    return SUCCESS;
}
    else {
        head = target -> link;
        
        if (target == tail)//head이자 tail node를 지우는 경우
        tail = prev; 
        delete target;
        return SUCCESS;
    }
}

void my_list::insert_a_node(string tname, node t)
{
    node *p, *target;
    p = new node;
    *(p) = t; 
    target = head;
    while(target != NULL && target -> name != tname){
        target = target -> link;
    }
    if(target ==NULL){
    p -> link = head;
    head = p;
    }
   
    else{
        p -> link = target -> link;
        target -> link = p;

        if(tail ==target)
        tail = p;
    }
    if(tail == NULL)
    tail = p;
}

void my_list::show_all_data()
{
    node *p;
    
    for(p = head; p!=NULL; p=p->link){
        cout<<p -> name<<", "<<p -> score<<endl;
    }
}
int main()
{
my_list    a;
node   tmp;
        tmp.set_data("Kim", 83.5);
        a.add_to_head(tmp);
        tmp.set_data("Lee", 58.2);
        a.add_to_head(tmp);
        tmp.set_data("Park", 91.3);
        a.add_to_head(tmp);
        tmp.set_data("Choi", 55.1);
        a.add_to_head(tmp);
        tmp.set_data("Ryu", 77.1);
        a.add_to_head(tmp);
        tmp.set_data("Yang", 41.3);
        a.add_to_head(tmp);
        tmp.set_data("Hong", 78.2);
        a.add_to_head(tmp);

        cout << "\nThe list before the test \n";
        a.show_all_data();

        a.remove_a_node("Ryu");

        cout << "\nThe list after the removal\n";

        a.show_all_data();

        tmp.set_data("Jeong", 97.5);
        a.insert_a_node("Choi", tmp);

        tmp.set_data("Cho", 85.5);
        a.insert_a_node("Kang", tmp);

        tmp.set_data("Jueun",100.0);
        a.add_to_tail(tmp);

        cout << "\nThe list after the insertions\n";

        a.show_all_data();

        return 0;
}

