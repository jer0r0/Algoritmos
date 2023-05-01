// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream> 
#include <string>
using namespace std;

int ini_potencia(int n, int k){
   
    if(k == 1){
        return n;
    }else{
        return n * ini_potencia(n, k-1);
    }
}


int main()
{
    int n = 2; 
    int k = 4; 
    
    cout<< ini_potencia(n,k)<<endl; 
    
    return 0;
}
