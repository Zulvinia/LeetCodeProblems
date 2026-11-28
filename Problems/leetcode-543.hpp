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

    int dfs(TreeNode* root, int& res)
    {
        if(root == nullptr)
            return 0;

        int left = dfs(root->left, res);
        int right = dfs(root->right, res);

        res = max(res, left+right);
        return 1 + max(left,right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }

    void TestCases()
    {
        // test case 1:
        {
            TreeNode* inputRoot = BuildBinaryTree("[1,null,2,3,4,5]");
            int ans = 3;
            int usrAns = diameterOfBinaryTree(inputRoot);

            std::cout << (ans == usrAns ? "Correct!" : "Incorrect!") << endl;
        }

        // test case 2:
        {
            TreeNode* inputRoot = BuildBinaryTree("[1,2,3]");
            int ans = 2;
            int usrAns = diameterOfBinaryTree(inputRoot);

            std::cout << (ans == usrAns ? "Correct!" : "Incorrect!") << endl;
        }
        
        // test case 3:
        {
            TreeNode* inputRoot = BuildBinaryTree("[1, 2, 3, 4, 5]");
            int ans = 3;
            int usrAns = diameterOfBinaryTree(inputRoot);

            std::cout << (ans == usrAns ? "Correct!" : "Incorrect!") << endl;
        }
    }
};