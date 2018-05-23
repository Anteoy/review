#include <iostream>
using namespace std;

class Base {
friend class Frnd;
protected:
    int i;
private:
    int k = 2;
};
class D1 : public Base {
protected:
    int j;
};
class Frnd {
public:
    int mem(Base b) { 
        cout << b.k << endl;
        return b.i; 
    }
    // 基类的友元对派生类的成员没有特殊访问权限
    // int mem(D1 d) { return d.i; } // 报错
};
class D2 : public Frnd {
public:
    //友元关系不能继承
    // int mem(Base b) { return b.i; } // 报错
};

int main(){
    Frnd *f;
    Base b;
    f->mem(b);
    return 0;
}