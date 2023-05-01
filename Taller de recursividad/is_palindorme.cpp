
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream> 
#include <string>
using namespace std;

bool isPalindrome(string str){
    int len = str.length();
   // cout<<str[0]<<endl;
    //cout<<str[len-1]<<endl;
    //cout<<str.substr(1,len-2)<<endl; 
    
    if(len <= 1){
        return true;
    }else{
        return (str[0]==str[len-1]) && isPalindrome(str.substr(1,len-2));
    }
}

int main()
{
    string a = "ADDA"; 
    cout<<isPalindrome(a)<<endl; 
    
    return 0;
}
