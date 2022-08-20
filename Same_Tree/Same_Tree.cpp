#include <iostream>
#include <queue>


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
    static bool isSameTree(TreeNode* p, TreeNode* q) {

        if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) return false;
        if (p == nullptr && q == nullptr) return true;
        else {
            if (p->val != q->val) return false;
            if (isSameTree(p->right, q->right) && isSameTree(p->left, q->left)) return true;
        }
        return false;
        

    }
};

int main()
{
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->left->left = nullptr;
    p->left->right = nullptr;
    p->right->left = nullptr;
    p->right->right = nullptr;
    
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    q->left->left = nullptr;
    q->left->right = nullptr;
    q->right->left = nullptr;
    q->right->right = nullptr;


    TreeNode* p2 = new TreeNode(1);
    p2->left = new TreeNode(2);
    p2->right = nullptr;
    p2->left->left = nullptr;  
    p2->left->right = nullptr;

    TreeNode* q2 = new TreeNode(1);
    q2->left = nullptr;
    q2->right = new TreeNode(2);
    q2->right->left = nullptr;
    q2->right->left = nullptr;
    
    if (Solution::isSameTree(p, q) == true) {
        std::cout << "Test comlete" << std::endl;
    }
    else {

        std::cout << "Test denied" << std::endl;
    }

    if (Solution::isSameTree(p2, q2) == false) {
        std::cout << "Test comlete" << std::endl;
    }
    else {

        std::cout << "Test denied" << std::endl;
    }
}

