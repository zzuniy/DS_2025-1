// 주어진 array의 앞쪽 n개 원소의 합, 1에서 n까지 정수 범위에서 짝수의 합
#include <iostream>
using namespace std;

int sum(int num);

int main(){
    int n, k;
    cin>>n;
    k=sum(n);
    cout<<k<<endl;
}

int sum(int num){
    if(num==0)
    return 0;
    if(num %2==0)
        return num+sum(num-2);
    else{
        return sum(num-1);
    }
}
