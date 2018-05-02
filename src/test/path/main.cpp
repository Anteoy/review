#include <iostream>
using namespace std;
#include <unistd.h>
#include <pwd.h>
std::string getUserName();

int main() {
    string rs;
    rs = getUserName();
    cout << rs <<endl;
}

std::string getUserName()  
{  
    uid_t userid;  
    struct passwd* pwd;  
    userid=getuid();  
    pwd=getpwuid(userid);  
    return pwd->pw_name;  
}  