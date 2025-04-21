#include <iostream>
using namespace std;

class weight{
public:
    int kg=0,g=0;
    void set_weight(int kg, int g);

    int get_weight();

};
weight add_weight(weight w1, weight w2);
bool less_than(weight w1, weight w2);

void weight:: set_weight(int input_kg, int input_g){
    kg = input_kg;
    g = input_g;
}

weight add_weight(weight w1, weight w2){
    weight result;
    int kg_count=0;
    int sumKg =0,sumG = 0;

    sumKg = w1.kg + w2.kg;
    sumG = w1.g + w2.g;

    while(sumG>1000){
        kg_count++;
        sumG-=1000;
    }
    sumKg += kg_count;

    result.kg  = sumKg;
    result.g  = sumG;
    return result;
}

int weight::get_weight(){
    int kg_to_gram=0;
    int gram_weight;

    kg_to_gram = kg * 1000;
    gram_weight = kg_to_gram + g;
    return gram_weight;
}

bool less_than(weight w1, weight w2){
    if(w1.get_weight() < w2.get_weight())
        return true;
    else
        return false;

}

int main(){
    weight w1, w2, w3; 
    w1.set_weight(3, 400);
    w2.set_weight(2,700);
    w3 = add_weight(w1,w2);
    cout<<w3.get_weight() << "gram\n";

    if(less_than(w1,w2))
        cout << "yes.\n";
    else 
        cout<<"no\n";

        return 0;

}