#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include "../Utilities/TreeNode.hpp"

using namespace std;
using namespace Utils::TreeNode;

class Solution
{
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;

        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }

    void TestCases()
    {
        // test case 1:
        {
            TreeNode* inputRoot = BuildBinaryTree("[1,2,3,null,null,4]");
            int ans = 3;
            int usrAns = maxDepth(inputRoot);

            std::cout << (usrAns == ans ? "Correct!" : "Incorrect!") << endl;            
        }

        // test case 2:
        {
            TreeNode* inputRoot = BuildBinaryTree("[]");
            int ans = 0;
            int usrAns = maxDepth(inputRoot);

            std::cout << (usrAns == ans ? "Correct!" : "Incorrect!") << endl;            
        }
    }
};