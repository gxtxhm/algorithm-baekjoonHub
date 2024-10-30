#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int cnt=0;
	string s;cin>>s;
    unordered_set<string>us;
    us.insert("c=");us.insert("c-");
    us.insert("dz=");us.insert("d-");
    us.insert("lj");us.insert("nj");
    us.insert("s=");us.insert("z=");
    string cur="";
    cur+=s[0];cur+=s[1];
    for(int i=2;i<s.length()+2;i++)
    {
        
        if(i<s.length())
        {
            cur+=s[i];
            if(cur.length()!=3)continue;
        }
        if(cur=="")continue;
        int j;
        
        for(j=0;j<cur.length();j++)
        {
            if(us.find(cur.substr(0,j+1))!=us.end())
            {
                break;
            }
        }
        if(cur.length()==1){cur="";cnt++;continue;}
        if(j==cur.length()){cur=cur.substr(1);}
        else if(j==cur.length()-1)cur="";
        else cur=cur.substr(j+1);
        cnt++;
    }
    cout<<cnt;
	return 0;
}