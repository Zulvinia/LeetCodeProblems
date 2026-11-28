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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return root;

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }

    void TestCases()
    {
        // test case 1:
        {
            TreeNode* inputRoot = BuildBinaryTree("[1,2,3,4,5,6,7]");
            TreeNode* ans = BuildBinaryTree("[1,3,2,7,6,5,4]");
            TreeNode* usrAns = invertTree(inputRoot);

            std::cout << (isSameTree(usrAns, ans) == true ? "Correct!" : "Incorrect!") << endl;
        }

        // test case 2:
        {
            TreeNode* inputRoot = BuildBinaryTree("[2,1,3]");
            TreeNode* ans = BuildBinaryTree("[2,3,1]");
            TreeNode* usrAns = invertTree(inputRoot);

            std::cout << (isSameTree(usrAns, ans) == true ? "Correct!" : "Incorrect!") << endl;
        }
        
        // test case 3:
        {
            TreeNode* inputRoot = BuildBinaryTree("[]");
            TreeNode* ans = BuildBinaryTree("[]");
            TreeNode* usrAns = invertTree(inputRoot);

            std::cout << (isSameTree(usrAns, ans) == true ? "Correct!" : "Incorrect!") << endl;
        }
    }
};