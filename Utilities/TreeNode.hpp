#pragma once
#include <string>
#include <queue>

namespace Utils
{
    namespace TreeNode
    {
        struct TreeNode
        {
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode() : val(0), left(nullptr), right(nullptr) {}
            TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
            TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
        };

        std::vector<TreeNode *> ConvertInputBinaryTreeStringToVector(const std::string &inputBinaryTree)
        {
            std::vector<TreeNode *> inputBinaryTreeVector;
            for (int i = 0; i < static_cast<int>(inputBinaryTree.size()); ++i)
            {
                if (inputBinaryTree[i] == '[' ||
                    inputBinaryTree[i] == ']' ||
                    inputBinaryTree[i] == ' ')
                {
                    continue;
                }

                if (inputBinaryTree[i] == 'n')
                {
                    inputBinaryTreeVector.push_back(nullptr);
                    i += 4;
                }
                else // its a number
                {
                    int it = static_cast<int>(inputBinaryTree.find(',', i + 1));

                    if (it == -1)
                        it = static_cast<int>(inputBinaryTree.size());

                    inputBinaryTreeVector.push_back(new TreeNode(std::stoi(std::string(inputBinaryTree.begin() + i, inputBinaryTree.begin() + it))));

                    i += it - i;
                }
            }

            return inputBinaryTreeVector;
        }

        TreeNode* CreateBinaryTree(const std::vector<TreeNode *> &inputBinaryTree)
        {
            TreeNode *root = nullptr;

            int inputBTSize = static_cast<int>(inputBinaryTree.size());

            if (inputBTSize == 0)
                return root;

            std::queue<TreeNode *> evalQueue;
            evalQueue.push(inputBinaryTree.front());
            int i = 1;
            root = inputBinaryTree.front();

            while (!evalQueue.empty())
            {
                TreeNode *evalNode = evalQueue.front();
                evalQueue.pop();

                // add left
                if (inputBTSize > i)
                {
                    if (inputBinaryTree[i] != nullptr)
                        evalQueue.push(inputBinaryTree[i]);

                    evalNode->left = inputBinaryTree[i];
                    ++i;
                }

                // add right
                if (inputBTSize > i)
                {
                    if (inputBinaryTree[i] != nullptr)
                        evalQueue.push(inputBinaryTree[i]);

                    evalNode->right = inputBinaryTree[i];
                    ++i;
                }
            }

            return root;
        }

        TreeNode* BuildBinaryTree(std::string inputBinaryTree)
        {
            // step 1: convert the users input string as a vector
            //         The users string must consist of an "array" of interger numbers, commas, and nulls
            std::vector<TreeNode *> inputBinaryTreeVector = ConvertInputBinaryTreeStringToVector(inputBinaryTree);

            // step 2: convert the vector of numbers and nulls to a Binary Tree:
            return CreateBinaryTree(inputBinaryTreeVector);
        }

        bool isSameTree(TreeNode* p, TreeNode* q) {

            if ((p == nullptr && q != nullptr) ||
                (p != nullptr && q == nullptr)) {
                return false;
            }

            if (p == nullptr && q == nullptr)
                return true;

            if (p->val != q->val) {
                return false;
            }

            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
} // namespace Utils