#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:

    vector<int> twoSum(vector<int>& nums, int target) {

        // m = <int - value, int - index>
        map<int, int> m = map<int, int>();

        for(int i = 0; i < static_cast<int>(nums.size()); ++i)
            m[nums[i]] = i;

        for(int i = 0; i < static_cast<int>(nums.size()); ++i)
        {
            int compliment = target - nums[i];
            if(m.find(compliment) != m.end() && m[compliment] != i) {
                return vector<int>({i, m[compliment]});
            }
        }

        return vector<int>({});
    }

    void TestCases()
    {
        // test case 1:
        {
            vector<int> nums = vector<int>({3,4,5,6});
            int target = 7;

            vector<int> usrAns = twoSum(nums, target);
            vector<int> ans = vector<int>({0,1});

            cout << (ans[0] == usrAns[0] && ans[1] == usrAns[1] ? "Correct!" : "Incorrect!") << endl; 
        }

        // test case 2:
        {
            vector<int> nums = vector<int>({4,5,6});
            int target = 10;

            vector<int> usrAns = twoSum(nums, target);
            vector<int> ans = vector<int>({0,2});

            cout << (ans[0] == usrAns[0] && ans[1] == usrAns[1] ? "Correct!" : "Incorrect!") << endl; 
        }

        // test case 3:
        {
            vector<int> nums = vector<int>({5,5});
            int target = 10;

            vector<int> usrAns = twoSum(nums, target);
            vector<int> ans = vector<int>({0,1});

            cout << (ans[0] == usrAns[0] && ans[1] == usrAns[1] ? "Correct!" : "Incorrect!") << endl; 
        }
    }
};