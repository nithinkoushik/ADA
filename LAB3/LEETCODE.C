/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool findTarget(struct TreeNode* root, int k) {
    int a[100000],top=0;
    io(root,a,&top);
    int low=0, high=top-1,sum;
    while(low<high){
        sum=a[low]+a[high];
        if(sum>k){
            high-=1;
        }
        else if(sum<k){
            low+=1;
        }
        else{
            return true;
        }
    }
    return false;
}
void io(struct TreeNode* root,int a[],int *top){
    if(root!=NULL){
        io(root->left,a,top);
        a[(*top)++]=root->val;
        io(root->right,a,top);
    }
}
