#include <string>
#include <vector>
#include <map>
using namespace std;

long long solution(string numbers) {
    long long answer = 0;
    string a = "";
    int size[10] = { 4,3,3,5,4,4,3,5,5,4 };
    int num[10] = { 0,1,2,3,4,5,6,7,8,9 };
    map<string, int> m;
    m.insert({ "ze",0 });
    m.insert({ "on",1 });
    m.insert({ "tw",2 });
    m.insert({ "th",3 });
    m.insert({ "fo",4 });
    m.insert({ "fi",5 });
    m.insert({ "si",6 });
    m.insert({ "se",7 });
    m.insert({ "ei",8 });
    m.insert({ "ni",9 });

    int cnt = 0;
    int len = numbers.length();
    while (cnt < len)
    {
        string b = "";
        b += numbers[cnt];
        b += numbers[cnt + 1];

        int id = m[b];
        cnt += size[id];
        a += num[id] + '0';
    }

    return stoull(a);
}