#include <iostream>
using namespace std;

// num은 인덱스 num이라는 뜻
//피보나치는 인덱스 0부터 있다.

int fibo(int num);

int main(){
    int n=0;
    int k=0;

    cin>>n;
    k= fibo(n);
    cout<<k<<endl;

}

int fibo(int num){
    if(num == 0)
    return 0;

    else if(num ==1)
    return 1;

    else
    return fibo(num-1)+fibo(num-2);
}
