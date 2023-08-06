#include <string>
#include <vector>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    int min = rank.size();
    int minId = -1;
    int h = 10000;
    for (int i = 0; i < 3; i++)
    {
        min = rank.size(); minId = -1;
        for (int j = 0; j < rank.size(); j++)
        {
            if (attendance[j] && min >= rank[j])
            {
                min = rank[j];
                minId = j;
            }
        }
        attendance[minId] = false;
        answer += (h * minId);
        h /= 100;
    }

    return answer;
}