/*Given a target node data and a root of binary tree. If the target is set on fire, determine the shortest amount of time needed to burn the entire binary tree.



It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.


Example 1

Input : root = [1, 2, 3, 4, null, 5, 6, null, 7]. target = 1

Output : 3

Explanation : The node with value 1 is set on fire.

In 1st second it burns node 2 and node 3.

In 2nd second it burns nodes 4, 5, 6.

In 3rd second it burns node 7.*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/


class Solution{
	public:

TreeNode* parentTracker(TreeNode*root, unordered_map<TreeNode*, TreeNode*> &parent, int target){
    if(!root)return NULL;
    //For every node we find its parent
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* targetN = NULL;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->data == target){
                targetN = node;
            }
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }

        }
        return targetN;
}
        int findMaxDistance(TreeNode* root, int target){
            unordered_map<TreeNode*, TreeNode*> parent;

            TreeNode* targetN = parentTracker(root, parent, target);
            unordered_map<TreeNode*, bool> visited;

            queue<TreeNode*> q;
            int dist = 0;
            q.push(targetN);
            while(!q.empty()){
                int size = q.size();
                bool burnedDown = false;
                for(int i = 0; i < size; i++){
                    TreeNode* node = q.front();
                    q.pop();

                    if(node->left && !visited[node->left]){
                        q.push(node->left);
                        visited[node->left] = true;
                        burnedDown = true;
                    }
                    if(node->right && !visited[node->right]){
                        q.push(node->right);
                        visited[node->right] = true;
                        burnedDown = true;
                    }
                    if(parent[node] && !visited[parent[node]]){
                        q.push(parent[node]);
                        visited[parent[node]] = true;
                        burnedDown = true;
                    }
                }
                if(burnedDown){
                    dist++;
                }
                /*
                    dist++;//Distance will only be incremented if and only if that level has nodes not when they are NULL here error is that only
                    */
            }
            return dist;
        }

		int timeToBurnTree(TreeNode* root, int start){
            if(!root)return 0;

        int minTime = findMaxDistance(root, start);

        return minTime;

    		}	
};//T.C. = o(2n) + O(LOGN){MAP}, S.C. = O(3N)