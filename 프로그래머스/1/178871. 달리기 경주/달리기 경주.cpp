#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string,int> m;
    
    for(int i=0;i<players.size();i++)
    {
        m.insert({players[i],i});    
    }
    // m[callings[i]] -> callings[i] 가 몇등인지
    // players[m[callings[i]]-1] -> 그 앞사람이 누구인지
    // m[players[m[callings[i]]-1]] -> 그 앞사람이 몇등인지
    for(int i=0;i<callings.size();i++)
    {
        string a = players[m[callings[i]]];
        string b =players[m[callings[i]]-1];
        players[m[callings[i]]] = players[m[callings[i]]-1];
        players[m[callings[i]]-1]=a;
        m[a]--;
        m[b]++;
        
    }
    
    
    return players;
}