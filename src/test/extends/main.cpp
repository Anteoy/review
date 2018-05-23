#include <iostream>
using namespace std;

class BaseClass{
public:
    int a;
    void test1();
    virtual void printFunc(){
    cout<<"This is BaseClass."<<endl;
    }
protected:
    int b;
    void test2();
private:
    int c;
};
class SubClassA : public BaseClass{
public:
    void printFunc(){
    cout<<"This is SubClassA"<<endl;
    }
    void testA(){
       cout<<a<<endl;
       cout<<b<<endl;
     //cout<<c<<endl; c私有成员无法继承
    }
private:
    int d;
};

// public继承是public到子类public,protectd到子类的protectd
// protectd继承是基类所有public,protectd都到子类的protectd
// private继承同理是到自己的private里面
int main(){
    SubClassA* d = new SubClassA();
    d->printFunc();
    return 0;
}