#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:

    bool isAnagram(string s, string t) {
        // Edge Case: both s and t must match in length. No Anagram can have different lengths.
        if(s.size() != t.size())
            return false;

        map<char, int> m = map<char, int>();

        // Step 1: Gather all the chars, including dupes from one string.
        for (size_t i = 0; i < s.size(); ++i)
        {
            ++m[s[i]];
        }

        // Step 2: remove chars one-by-one using the second string, the remainder from the hash map will tell us whether its an anagram:
        for(size_t i = 0; i < t.size(); ++i)
        {
            char c = t[i];
            // verify the char is in the map. Verify that the char is non-zero before subtracting
            if(m.find(c) != m.end() && m[c] > 0) {
                --m[c];

                if(m[c]==0)
                    m.erase(c);
            }
            else {
                return false;
            }
        }

        // Step 3: Verify all characters have been used from the first string.
        // M : S,0 | T,1 | A,0 | M,0
        if(m.size() > 0)
            return false;

        return true;
    }

    void TestCases()
    {
        // test case 1:
        {
            string s = "racecar";
            string t = "carrace";

            bool usrAns = isAnagram(s,t);
            bool ans = true;

            cout << (usrAns == ans ? "Correct!" : "Incorrect!") << endl;
        }

        // test case 2:
        {
            string s = "jar";
            string t = "jam";

            bool usrAns = isAnagram(s,t);
            bool ans = false;

            cout << (usrAns == ans ? "Correct!" : "Incorrect!") << endl;
        }

        // test case 3:
        {
            string s = "stam";
            string t = "sam";

            bool usrAns = isAnagram(s,t);
            bool ans = false;

            cout << (usrAns == ans ? "Correct!" : "Incorrect!") << endl;
        }        
    }
};