#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> lectures(n);
    for (int i = 0; i < n; i++) {
        cin >> lectures[i].first >> lectures[i].second;
    }

    // 시작 시간을 기준으로 정렬
    sort(lectures.begin(), lectures.end());

    // 종료 시간을 저장하는 최소 힙
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(lectures[0].second);

    for (int i = 1; i < n; i++) {
        if (pq.top() <= lectures[i].first) {
            pq.pop();  // 기존 강의실을 사용할 수 있으므로 제거
        }
        pq.push(lectures[i].second);  // 새 강의 종료 시간 추가
    }

    cout << pq.size();  // 필요한 강의실 개수
    return 0;
}
