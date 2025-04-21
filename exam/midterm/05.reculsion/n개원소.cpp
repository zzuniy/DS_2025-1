// 주어진 array의 앞쪽 n개 원소의 합, 1에서 n까지 정수 범위에서 짝수의 합
#include <iostream>
using namespace std;

int arraySum(int arr[], int n);
int main(){
    int array[5] = {1,2,3,4,5};
    int n,k;

    cin>>n;

    k= arraySum(array,n);
    cout<<k<<endl;
}

int arraySum(int arr[], int n){
    if(n==0)
    return 0;

    else
    return arr[n-1]+ arraySum(arr,n-1);
}

