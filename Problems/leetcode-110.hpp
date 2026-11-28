#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "../Utilities/TreeNode.hpp"

using namespace std;
using namespace Utils::TreeNode;

class Solution
{
public:

    pair<bool, int> dfs(TreeNode* root)
    {
        if(root == nullptr)
            return make_pair(true, 0);

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int balanced = left.first && right.first && (abs(left.second - right.second) <= 1);
        return make_pair(balanced, 1 + max(left.second, right.second));
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }

    void TestCases()
    {
        // test case 1:
        {
            TreeNode* inputRoot = BuildBinaryTree("[1,2,3,null,null,4]");
            bool ans = true;
            bool usrAns = isBalanced(inputRoot);

            std::cout << (usrAns == ans ? "Correct!" : "Incorrect!") << endl;            
        }

        // test case 2:
        {
            TreeNode* inputRoot = BuildBinaryTree("[1,2,3,null,null,4,null,5]");
            bool ans = false;
            bool usrAns = isBalanced(inputRoot);

            std::cout << (usrAns == ans ? "Correct!" : "Incorrect!") << endl;            
        }

        // test case 2:
        {
            TreeNode* inputRoot = BuildBinaryTree("[]");
            bool ans = true;
            bool usrAns = isBalanced(inputRoot);

            std::cout << (usrAns == ans ? "Correct!" : "Incorrect!") << endl;            
        }
    }
};