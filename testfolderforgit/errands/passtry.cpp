#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

int main()
{
    system("stty -echo");
    string s;
    cin>>s;
    cout << s << endl;
    system("stty -echo");
    return 0;
}//main 