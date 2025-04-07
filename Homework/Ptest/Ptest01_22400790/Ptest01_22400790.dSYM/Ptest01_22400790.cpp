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
        my_list(); // head 초기화
        void add_to_head(node   t); //head 새로 가리키기
        double   score_sum(); //점수의 함 구하기
        int   num_nodes(); //노드의 갯수
        double   get_score(string tname); //이름 검색하기
        int count_high_scores(); //점수가 80이상인 node수
        void show_all_data(); //모든 데이타 출력
};

my_list::my_list()
{
        head = NULL;
}


void my_list::add_to_head(node t) {
        node   *p;
        p = new   node;
        (*p) = t;
        p->link = head;
        head = p;
}

int   my_list::num_nodes()
{
        node   *t;
        int count = 0;
        for (t = head; t != NULL; t = t->link)
        count++;
        return count;
}

double   my_list::score_sum() 
{       node *t;
        double scoreSum=0;
        for (t=head; t!=NULL; t= t->link){
            scoreSum+=t->score;
        }
        return scoreSum;
}

int   my_list::count_high_scores()
{       node *t;
        int count=0;
        for (t=head; t!=NULL; t= t->link){
            if(t->score >= 80)
            count++;
        }
        return count;

}

double   my_list::get_score(string tname)
{   node *target = head;
    while((target!=NULL)&&(target->name!=tname)){
                target = target -> link;
                if(target -> name == tname)
                break;
    }
        
        return target -> score;

    return -1;
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

        cout << "\nThe list before the test \n";
        a.show_all_data();

        cout << "\nThe Number of nodes : " << a.num_nodes() << endl;

        double average = a.score_sum() / a.num_nodes();

        cout << "The Average : " << average << endl;

        cout << "The number of high scores(higher than 80) : " << a.count_high_scores() << endl;

        cout << "Choi's score : " << a.get_score("Choi") << endl;

        return 0;

}






