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
class Solution {
public:

    int inorder(TreeNode* node, int &count, int k){
        if(!node)return -1;

//We check this when we have travelled the smaller elements than node
        // if(count == k){
        //     return node->val;
        // }
    // int elem = inorder(node->left, count + 1, k);
/*Since count is passed by reference (int &count), you can't pass count + 1 into the recursive calls. C++ won't let you bind a temporary value like count + 1 to a non-const reference.*/
/*we should only increment count when we actually "visit" the root node. That means we increment it after we fully explore the left subtree, not when passing it down.*/
    int elem = inorder(node->left, count, k);
/*Check if we found the element in the left subtree (e.g., if the returned value is not -1, return it).
If not found, then increment count for the current node and check if count == k.*/

    if(elem != -1)return elem;

    // else count++;
    //Not needed bcz the count already comes incremented for thr node val from first inorder

        if(count == k){
            return node->val;
        }
        count++;
        
    //     elem = inorder(node->right, count, k);
    // if(elem != -1)return elem;
    // else count++;
    return inorder(node->right, count, k);

    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root)return -1;
        TreeNode* node = root;

    int count = 1;

    int elem = inorder(root, count, k);
        
    return elem;

    }
};/*Optimal:
Using a count variable while inordering recursively
T.C. = O(N), S.C. = O(N)*/
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
class Solution {
public:

    int kthSmallest(TreeNode* root, int k) {
        if(!root)return -1;
        TreeNode* node = root;

    int count = 1;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    int elem = -1;
    while(true){
        if(curr){
            st.push(curr);
            curr = curr->left;
        }
        else{
            if(st.empty())break;
            curr = st.top();
            st.pop();
            if(count == k){
                elem = curr->val;
                break;
            }
            count++;
            curr = curr->right;
        }
    }

    return elem;

    }
};/*Optimal: Using iterative inorder traversal with count var;
T.C. = O(N), S.C. = O(N)*/