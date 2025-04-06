# include <iostream>
using namespace std;

class weight{
    int kg, gram;
    public: 

    int get_weight();
    void set_weight(int n1, int n2);
    int is_heavy();

    void add_grams(int n);
    weight add_weight(weight w1, weight w2);
};

int weight::get_weight(){
    return kg*1000+gram;
}

void weight:: set_weight(int n1, int n2){
    kg=n1;
    gram = n2;
}

int weight:: is_heavy(){
    if(kg>=10){
        return 1;
    }
    else{
        return 0;
    }
}

void weight:: add_grams(int n){
    gram += n;
    if(gram>=1000){
        kg++;
        gram -= 1000;
    }
}

weight weight:: add_weight(weight w1, weight w2){
    weight result;
    result.kg = w1.kg + w2.kg;
    result.gram =  w1.gram +w2.gram;

    if (result.gram >= 1000) {
        result.kg += result.gram / 1000; // kg에 추가
        result.gram = result.gram % 1000; // 남은 gram
    }
    return result;
}

int main( )
{
weight  w1, w2, w3;  // weight라는 class object 3개 생성

    w1.set_weight(12, 800);  // w1을 12kg 800 g으로

    if ( w1.is_heavy() )       //  w1이 10 kg 이상의 값인가 check

        cout << "Heavy. \n";  // 10 이상의 값이므로 Heavy 출력

    else

        cout << "Light. \n";

    w2.set_weight(2, 900);  // w2을 2kg 900 g으로

    w2.add_grams(500);   // gram 값에 500을 더함, w2값이 3kg 400 gram으로 변화

    w3 = w3.add_weight(w1, w2); // w1과 w2을 더하여 w3에 à w3는 16kg 200g

    cout << w3.get_weight() << " grams\n"; // w3의 값 ‘16200 grams’ 출력

}