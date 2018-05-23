#include <iostream>
using namespace std;

// ref: http://blog.51cto.com/6924918/1279707
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
class DerivedClassA : public BaseClass{
public:
    void printFunc(){
    cout<<"This is DerivedClassA"<<endl;
    }
    void testA(){
       cout<<a<<endl;
       cout<<b<<endl;
     //cout<<c<<endl; c私有成员无法继承
    }
private:
    int d;
};

class DerivedClassB : public BaseClass{
public:
    void printFunc(){
        cout<<"This is DerivedClassB."<<endl;
    }
    void printFunc(int a){
        cout<<"a is:" << a << endl;
    }
};

// private成员只能由基类的成员和友元访问。
// public继承是public到子类public,protectd到子类的protectd
// protectd继承是基类所有public,protectd都到子类的protectd
// private继承同理是到自己的private里面

// 多态
// C++ 中的函数调用默认不使用动态绑定。要触发动态绑定，满足两个条件：
// 第一，只有指定为虚函数的成员函数才能进行动态绑定，成员函数默认为非虚函数，非虚函数不进行动态绑定；
// 第二，必须通过基类类型的引用或指针进行函数调用
int main(){
    DerivedClassA* d = new DerivedClassA();
    d->printFunc();
    delete d;
    d = 0;

    cout << "---------------" << endl;
    BaseClass *b1,*b2,*b3;
    BaseClass bc;
    DerivedClassA dcA;
    DerivedClassB dcB;
    b1 = &bc;
    b2 = &dcA;
    b3 = &dcB;
    b1->printFunc(); //调用基类的方法
    b2->printFunc();  //调用派生类A的方法
    b3->printFunc();  //调用派生类B的方法
    dcB.printFunc(6);
    return 0;
}