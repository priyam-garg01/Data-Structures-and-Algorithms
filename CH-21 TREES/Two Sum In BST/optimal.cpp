/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BstIterator{
stack<TreeNode*> st;
//reverse -> true -> before
//reverse -> false -> next
bool reverse = true;
public:
    BstIterator(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);

    }
    bool hasNext(){
        if(!st.empty())return true;
        return false;
    }

    int next(){
        TreeNode* curr = st.top();
        st.pop();
        if(!reverse)pushAll(curr->right);
        else{
            pushAll(curr->left);
        }
        return curr->val;
    }
private: 
    void pushAll(TreeNode* node){
        while(node){
            st.push(node);
            if(reverse == true){
                node = node->right;
            }
            else{
                node = node->left;
            }
        }
    }
};
class Solution {
public:
    
    
    bool findTarget(TreeNode* root, int k) {
        
        BstIterator l(root, false);//ascending order
        BstIterator r(root, true);//descending order

        int i = l.next();
        int j = r.next();

        while(i < j){
            if(i + j == k)return true;
            
            else if(i + j < k)//i++;
                i = l.next();
            else //j--;
                j = r.next();
        }
        return false;
    }
};/*//We apply the logic as used in binary search iterator that we use the algo for next funct, create algo for before function in the same way and then iterate through both like in simple 2 sum problem
Using a reverse boolean to get the reverse of the next function that is before and applying the same condition everywhere
T.C. = O(N) + O(1){only reqd for the traversal for 2 sum algo}
S.C. = O(H)*2{For both before and after}*/