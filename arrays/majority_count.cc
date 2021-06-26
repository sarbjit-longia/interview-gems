//Boyer-Moore voting algo
#include <vector>

using namespace std;

int find_n_by_2_majority(std::vector<int> &nums)
{
    int count = 0, candidate;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            candidate = nums[i];
            count = 1;
        }
        else
        {
            if (nums[i] == candidate)
                count++;
            else
                count--;
        }
    }
    return candidate;
}

int find_n_by_3_majority(std::vector<int> &nums)
{
    int count1 = 0, count2 = 0, cand1 = INT_MIN, cand2 = INT_MIN;

    for (auto x : nums)
    {
        if (x == cand1)
            count1++;
        else if (x == cand2)
            count2++;
        else if (count1 == 0)
        {
            cand1 = x;
            count1 = 1;
        }
        else if (count2 == 0)
        {
            cand2 = x;
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    //but in this you have to verify also that the obtained candidates are actual candidates or not
    count1 = 0, count2 = 0;
    for (auto x : nums)
    {
        if (x == cand1)
            count1++;
        if (x == cand2)
            count2++;
    }
    vector<int> v;
    if (count1 > nums.size() / 3)
        v.push_back(cand1);
    if (count2 > nums.size() / 3)
        v.push_back(cand2);
    return v;
}