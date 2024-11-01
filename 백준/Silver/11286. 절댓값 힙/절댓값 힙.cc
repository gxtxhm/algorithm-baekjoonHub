#include<bits/stdc++.h>
using namespace std;

struct compare {
    bool operator()(int a, int b) {
        if (abs(a) > abs(b)) return true; // 절댓값이 큰 경우 우선순위를 낮춤
        else if (abs(a) == abs(b)) return a > b; // 절댓값이 같을 때 더 큰 값을 우선순위를 낮춤
        return false; // 절댓값이 작은 경우 우선순위를 높임
    }
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n;cin>>n;
    
    priority_queue<int,vector<int>,compare> pq;
	
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        if(a==0)
        {
            if(pq.empty())cout<<0<<'\n';
            else {
                cout<<pq.top()<<'\n';pq.pop();
            }
        }
        else
        {
            pq.push(a);
        }
    }
	return 0;
}