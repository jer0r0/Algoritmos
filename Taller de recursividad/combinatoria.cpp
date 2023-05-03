
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>

using namespace std;

int combinatoria( int n, int k){
    if(n == 0 || k ==0 || n == k ){
        return 1;         
    }else{
        return combinatoria(n-1, k-1) + combinatoria(n-1, k);
    }
}
int main()
{
    int a, b; 
    a = 5;
    b = 3;
    cout<< combinatoria(a,b); 
    return 0;
}
