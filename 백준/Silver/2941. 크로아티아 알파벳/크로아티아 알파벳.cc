#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_set<string> croatia = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    int count = 0;

    for (int i = 0; i < s.length();) {  // i는 루프 내부에서만 증가
        bool found = false;
        
        // 3글자, 2글자, 1글자 순서대로 크로아티아 알파벳 확인
        for (int len = 3; len > 0; len--) {
            if (i + len <= s.length() && croatia.find(s.substr(i, len)) != croatia.end()) {
                count++;
                i += len;  // 발견된 경우 len만큼 건너뜁니다
                found = true;
                break;
            }
        }
        
        // 크로아티아 알파벳이 아닌 일반 알파벳이면 1글자 증가
        if (!found) {
            count++;
            i++;
        }
    }
    
    cout << count << endl;
    return 0;
}
