//Учитывая бинарное дерево, определите, сбалансировано ли оно по высоте.

//Для этой задачи сбалансированное по высоте бинарное дерево определяется как :

//бинарное дерево, в котором левое и правое поддеревья каждого узла отличаются по высоте не более чем на 1.

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};

class Solution {
public:
    static bool isBalanced(TreeNode* root) {

        if (!root)
            return true;

        TreeNode* leftTree = root->left;
        TreeNode* rightTree = root->right;

        
        return (abs(calcHeight(leftTree) - calcHeight(rightTree)) <= 1) && isBalanced(leftTree) && isBalanced(rightTree);
    }

    static int calcHeight(TreeNode* root) {
    
        if (!root)
            return 0;
        return 1 + max(calcHeight(root->left), calcHeight(root->right));
    }
};

int main()
{
    TreeNode* p = new TreeNode(3);

    p->left = new TreeNode(9);
    p->right = new TreeNode(20);

    p->left->left = nullptr;
    p->left->right = nullptr;
    p->right->left = new TreeNode(15);
    p->right->right = new TreeNode(7);
    
    p->right->left->left = nullptr;
    p->right->right->right = nullptr;    
    p->right->left->left = nullptr;
    p->right->right->right = nullptr;

    if (Solution::isBalanced(p) == true) {
        std::cout << "Test comlete" << std::endl;
    }
    else {

        std::cout << "Test denied" << std::endl;
    }
}
