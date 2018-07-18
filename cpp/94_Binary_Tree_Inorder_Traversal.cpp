#include <iostream>
#include <vector>
#include <functional>

using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> numbers;
        std::function<void (TreeNode*)> inorder = [&](TreeNode* root)
        {
            if(root == NULL)
                return NULL;
            inorder(root->left);
            numbers.push_back(root->val);
            inorder(root->right);
        };
        while(!numbers.empty())
        {
            numbers.pop_back();
        }
        inorder(root);
        return numbers;
    }
};

TreeNode* create_tree(int* val_list, int length)
{
    // Preorder
    if(length <=0)
        return NULL;
    TreeNode* root = NULL;
    // Create with preorder
    vector<TreeNode*> tree;
    TreeNode* root_ptr = NULL;
    TreeNode* left_ptr = NULL;
    TreeNode* right_ptr = NULL;
    int i=0;
    while(i<length) {
        TreeNode *node = NULL;
        // Root
        if(val_list[i]!=NULL){
            node = new TreeNode(val_list[i]);
            if(i==0)
                root = node;
        }else{
            i++;
            continue;
        }
        root_ptr = node;

        i++;
        // Left
        if(i<length) {
            if(val_list[i+1])
            TreeNode *node = new TreeNode()
        }

    }
//    for(int i=1; i<length; i++)
//    {
//        if(val_list[i]==NULL) {
//
//        }
//
//
//    }



    return root;
}

void preorder_tree(TreeNode* root)
{
    if(root==NULL) {
        return;
    }
    cout<<root->val<<"->";
    preorder_tree(root->left);
    preorder_tree(root->right);
}

void clean_tree(TreeNode* root)
{
    if(root==NULL)
        return;
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    delete(root);
    clean_tree(left);
    clean_tree(right);
}


int main()
{
    const int len = 5;
    int a[len] ={1,NULL,3};
    auto root = create_tree(a, len);
    //preorder_tree(root);

    // do something
    Solution solu;
    auto numbers = solu.inorderTraversal(root);
    for(auto i:numbers)
        cout<<i<<"  ";
    clean_tree(root);
    return 0;
}