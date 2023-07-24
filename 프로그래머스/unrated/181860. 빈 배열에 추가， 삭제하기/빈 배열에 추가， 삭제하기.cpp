

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag) {
    vector<int> answer;
    vector<int> a;
    for (int i = 0; i < arr.size(); i++)
    {
        if (flag[i])
        {
            for (int k = 0; k < arr[i] * 2; k++)a.push_back(arr[i]);

        }
        else
        {
            int cnt = 0;
            for (int k = 1; cnt<arr[i]; k++)
            {
                if (a[a.size() - k] != -1) {
                    a[a.size() - k] = -1; cnt++;
                }
                
            }
        }
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != -1)answer.push_back(a[i]);
    }
    return answer;
}
