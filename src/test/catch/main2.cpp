#include <stdexcept>
#include <iostream>

using namespace std;

void test() {
    throw runtime_error("just for test!");
    // terminate called after throwing an instance of 'char const*'
    // throw "just for test!";
}

int main() {
    try {
        test();
    } catch(runtime_error err) {
        cout << err.what() << endl;
    }
    // } catch(runtime_error err) {
    //     cout << err.what() << endl;
    // }
    return 0;
}