#include <iostream>
#include <string>
using namespace std;

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
public:
        my_list() {
                head = NULL;
        }
        void add_to_head(node   t);
        void delete_low_score(double n);
        void show_all_data();
};

void my_list::add_to_head(node t) {
        node   *p;
        p = new   node;
        (*p) = t;
        p->link = head;
        head = p;
}

void my_list::delete_low_score(double n)
{
    // node *prev, *target;
    // prev = NULL;
    // cout<<target -> score;
    
    // for(target = head; target !=NULL; target = target -> link)
    // {
    //     prev = target;
    //     if(target -> score>60.0){
    //         // cout<<"oh"<<target->score<<endl;
    //         if(prev ==NULL)
    //         head = target -> link;
    //         else{
    //         prev -> link = target -> link;
    //         }
    //         delete target;
    //     }
    // }
    
    
    node *prev, *target;
    prev = NULL;
    target = head;

    for(target = head; target !=NULL; target = target -> link){
        prev = target;
        target = target -> link;
        if(target -> score<n){
            
             if(prev==head){ 
                head = target -> link;
    
            delete target;
            }
            else {
                prev -> link = target -> link;
                delete target;
            }
         }
    }
}

void my_list::show_all_data()
{
        node *p;

        for ( p = head; p != NULL; p = p->link)
                cout << p->name << " : " << p->score << endl;

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

        cout << "\nThe list ----- \n" ;
        a.show_all_data();

        a.delete_low_score(60.0);
        cout << "\nThe list after the deletion\n" ;

        a.show_all_data();
        cout << endl;

        return 0;

}
