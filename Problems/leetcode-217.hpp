#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> dupes = map<int,int>();

        for (size_t i = 0; i < nums.size(); ++i)
        {
            ++dupes[nums[i]];
            if(dupes[nums[i]] > 1)
                return true;
        }
        
        return false;
    }


    void TestCases()
    {
        // test case 1:
        {
            vector<int> nums = vector<int>({1,2,3,3});
            bool usrAns = hasDuplicate(nums);
            bool ans = true;

            cout << (usrAns == ans ? "Correct!" : "Incorrect!") << endl;
        }

        // test case 2:
        {
            vector<int> nums = vector<int>({1,2,3,4});
            bool usrAns = hasDuplicate(nums);
            bool ans = false;

            cout << (usrAns == ans ? "Correct!" : "Incorrect!") << endl;
        }
    }
};