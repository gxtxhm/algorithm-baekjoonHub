#include <string>
#include <vector>

using namespace std;

vector<int> solution(int k, vector<int> score) 
{
    vector<int> answer;

    vector<int>arr;
    

    int min = 2001;
    int minId = -1;


    for (int i = 0; i < k; i++)
    {
        if (i >= score.size())
            return answer;
        arr.push_back(score[i]);
        if (min > arr[i])
        {
            minId = i;
            min = arr[i];
        }
        answer.push_back(min);
    }
    
    

    for (int i = k; i < score.size(); i++)
    {
        if (min < score[i])
        {
            arr[minId] = score[i];
            min = score[i];
            for (int j = 0; j < k; j++)
            {
                if (min > arr[j])
                {
                    minId = j;
                    min = arr[j];
                }
            }
            answer.push_back(min);
        }
        else
            answer.push_back(min);
    }


    return answer;
}