#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]>96)str[i]-=32;
        else str[i]+=32;
        cout<<str[i];
    }
    return 0;
}