#pragma once
#include <iostream>
#include <stack>
#include "../Utilities/TreeNode.hpp"

using namespace std;
using namespace Utils::TreeNode;

class Solution
{
public:

    void dfs(TreeNode* p, TreeNode* q, bool &res)
    {
        if(p == nullptr && q == nullptr)
            return;

        if(res == false)
            return;

        if((p == nullptr && q != nullptr) || 
           (p != nullptr && q == nullptr) ||
            p->val != q->val)
        {
            res = false;
            return;
        }

        dfs(p->left, q->left, res);
        dfs(p->right, q->right, res);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool res = true;
        dfs(p,q, res);
        return res;
    }

    void TestCases()
    {
        // test case 1:
        {
            TreeNode* inputP = BuildBinaryTree("[1,2,3]");
            TreeNode* inputQ = BuildBinaryTree("[1,2,3]");

            bool ans = true;
            bool usrAns = isSameTree(inputP, inputQ);

            std::cout << (usrAns == ans ? "Correct!" : "Incorrect!") << endl;            
        }

        // test case 2:
        {
            TreeNode* inputP = BuildBinaryTree("[4,7]");
            TreeNode* inputQ = BuildBinaryTree("[4,null,7]");

            bool ans = false;
            bool usrAns = isSameTree(inputP, inputQ);

            std::cout << (usrAns == ans ? "Correct!" : "Incorrect!") << endl;           
        }

        // test case 3:
        {
            TreeNode* inputP = BuildBinaryTree("[1,2,3]");
            TreeNode* inputQ = BuildBinaryTree("[1,3,2]");

            bool ans = false;
            bool usrAns = isSameTree(inputP, inputQ);

            std::cout << (usrAns == ans ? "Correct!" : "Incorrect!") << endl;           
        }
    }
};