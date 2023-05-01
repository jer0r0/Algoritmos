// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream> 
#include <string>
using namespace std;

char reverse_char( string &s , string &r, int a){
    char ch = s.at(a); 
    if( a  == s.length()-1){
        return ch;  
    }else{
        r += reverse_char(s,r, a+1 );
        return ch;
    }
}

string ini_reverse(string &s){
    string r = ""; 
    r += reverse_char(s,r,0);
    return r; 
}

int main()
{
    string a = "Welcome to Online IDE!! Happy Coding :)";
    cout<< a << endl;
    cout<<"El reverso de "<< a << " es: \n"<<ini_reverse(a)<<endl; 
    
    return 0;
}
