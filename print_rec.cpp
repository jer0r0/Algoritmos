
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>

using namespace std;
int der(int i){
    int der = 2*(i+1);
    return der;
}
int izq(int i){
    int izq = 2*(i+1)-1;
    return izq;
}

void print_rec(int* v, int n, int i){
    if(izq(i)<n){
        print_rec(v, n, izq(i));
    }
    if( der(i)<n){
        print_rec(v, n ,der(i));
    }
        cout<<v[i]<<" ";
}

int main()
{
    int n = 9 ; 
    int v[n] = {7,2,4,9,8,3,1,5,6}; 
    print_rec(v, n, 0); 
    return 0;
}
