#include <iostream>
using namespace std;

int factorial(int num);
int main(){
    int n;
    int k;
    cin>>n;
    k = factorial(n);

    cout<<k<<endl;
    
}
int factorial(int num){
    if(num==0)
    return 1;

    else{
        return num*factorial(num-1);
    }
}