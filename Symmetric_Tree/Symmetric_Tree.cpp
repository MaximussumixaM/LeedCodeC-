//Учитывая корень бинарного дерева, проверьте, является ли он зеркалом 
//самого себя(т.Е.Симметричным относительно своего центра).
#include <iostream>

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
    static bool isSymmetric(TreeNode* root) {

        TreeNode* LeftSubTree = root->left;
        TreeNode* RightSubTree = root->right;

        return isSym(LeftSubTree, RightSubTree);
    }

    static bool isSym(TreeNode* leftTree, TreeNode* rightTree) {

        if ((leftTree == nullptr && rightTree != nullptr) || (leftTree != nullptr && rightTree == nullptr)) return false;
        
        if (leftTree == nullptr && rightTree == nullptr) return true;

        else {

            if (leftTree->val != rightTree->val) return false;
            if (isSym(leftTree->left, rightTree->right) && isSym(leftTree->right, rightTree->left)) {

                return true;
            }
        }

    


    }
};

int main()
{
    TreeNode* p = new TreeNode(1);

    p->left = new TreeNode(2);
    p->right = new TreeNode(2);

    p->left->left = new TreeNode(3);
    p->left->right = new TreeNode(4);
    p->right->left = new TreeNode(4);
    p->right->right = new TreeNode(3);

    p->left->left->left = nullptr;
    p->left->right->right = nullptr;
    p->right->left->left = nullptr;
    p->right->right->right = nullptr;
    p->left->left->left = nullptr;
    p->left->right->right = nullptr;
    p->right->left->left = nullptr;
    p->right->right->right = nullptr;


    if (Solution::isSymmetric(p) == true) {
        std::cout << "Test comlete" << std::endl;
    }
    else {

        std::cout << "Test denied" << std::endl;
    }
}
