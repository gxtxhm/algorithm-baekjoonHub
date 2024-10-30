#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n;
    cin>>n;
    int cnt=99;
    if(n<=110)
    {
        if(n<=99)cout<<n;
        else cout<<99;
        return 0;
    }
    else if(n==1000){cout<<144;return 0;}
    else if(n>110)
    {
        cnt+=(n/100-1)*5;
        for(int i=n - n%100;i<=n;i++)
        {
            int d,d2;
            int a,b,c;
            a= i/100;
            b = (i%100)/10;
            c=i%10;
            d=a-b; d2=b-c;
            if(d==d2)cnt++;
        }
    }
	cout<<cnt;
	return 0;
}