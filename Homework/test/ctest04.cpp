#include <iostream>
#include <string>

//  An ordered list using linked list
//  Practice in class

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
        void ordered_list_insert(node   t);
        void show_all_data();
};

void my_list::ordered_list_insert(node t)
{
       


}

void my_list::show_all_data()
{
        node *p;

        for ( p = head; p != NULL; p = p->link)
                cout << p->name << " : " << p->score << endl;

}

int main()
{
my_list    thelist;
node   tmp;
        tmp.set_data("Kim", 73.5);
        thelist.ordered_list_insert(tmp);
        tmp.set_data("Lee", 82.2);
        thelist.ordered_list_insert(tmp);
        tmp.set_data("Park", 51.3);
        thelist.ordered_list_insert(tmp);
        tmp.set_data("Choi", 95.1);
        thelist.ordered_list_insert(tmp);
        tmp.set_data("Ryu", 71.3);
        thelist.ordered_list_insert(tmp);
        tmp.set_data("Yang", 58.2);
        thelist.ordered_list_insert(tmp);
        tmp.set_data("Hong", 83.5);
        thelist.ordered_list_insert(tmp);

        cout << "\nThe list after insertions\n";
        thelist.show_all_data();
        cout << endl;

        return 0;
}



