#include <iostream>
#include <string>
#include <exception>
using namespace std;
int main(){
    string str = "https://anteoy.site";
  
    try{
        char ch1 = str[100];
        cout<<ch1<<endl;
    }catch(exception e){
        cout<<"[1]out of bound!"<<endl;
    }
    try{
        char ch2 = str.at(100);
        cout<<ch2<<endl;
    }catch(exception &e){  //exception类位于<exception>头文件中
        cout<<"[2]out of bound!"<<endl;
    }
    try{
        throw "Unknown Exception";  //抛出异常
        cout<<"This statement will not be executed."<<endl;
    }catch(const char* &e){
        cout<<e<<endl;
    }
    return 0;
}