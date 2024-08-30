#include <iostream>
#include <vector>
#include <set>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<set<int>> wins(n + 1);
    vector<set<int>> losses(n + 1);
    
    for (auto result : results) {
        int winner = result[0];
        int loser = result[1];
        wins[winner].insert(loser);
        losses[loser].insert(winner);
    }
    
    for (int player = 1; player <= n; ++player) {
        for (auto winner : losses[player]) {
            wins[winner].insert(wins[player].begin(), wins[player].end());
        }
        for (auto loser : wins[player]) {
            losses[loser].insert(losses[player].begin(), losses[player].end());
        }
    }
    
    int count = 0;
    for (int player = 1; player <= n; ++player) {
        if (wins[player].size() + losses[player].size() == n - 1) {
            ++count;
        }
    }
    
    return count;
}