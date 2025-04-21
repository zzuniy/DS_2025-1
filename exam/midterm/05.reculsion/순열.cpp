#include <iostream>
using namespace std;

int permutation(int num, int num_select);
int main(){
    int n,n1;
    int k;
    cin>>n>>n1;
    k = permutation(n,n1);
    cout<<k<<endl;
}
int permutation(int num, int num_select){
        if(num_select==0)
        return 1;

        else{
            return num*permutation(num-1,num_select-1);
        }
}