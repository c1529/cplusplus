#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr), right(nullptr){}
};

vector<int> bfs(TreeNode* root){
    queue<TreeNode*> queue1;
    queue1.push(root);
    vector<int> vec;
    while(!queue1.empty()){
        TreeNode* node = queue1.front();
        queue1.pop();
        vec.push_back(node->val);
        if(node->left){
            queue1.push(node->left);
        }
        if(node->right){
            queue1.push(node->right);
        }
    }
    return vec;
}


int main()
{
    vector<TreeNode *> nums(5);
    for(int i=0;i<5;i++){
        nums[i] = new TreeNode(i*i*i);
    }
    nums[0]->left = nums[1];
    nums[0]->right = nums[2];
    nums[1]->left = nums[3];
    nums[1]->right = nums[4];
    vector<int> res = bfs(nums[0]);
    for(int i:res){
        cout<<i<<" ";
    }
    return 0;
}



