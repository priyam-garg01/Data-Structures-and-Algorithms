/*Given a pair of tree traversal, return true if a unique binary tree can be constructed otherwise false. Each traversal is represented with integer: 1 -> Preorder , 2 -> Inorder , 3 -> Postorder.


Example 1

Input : 1 2

Output : true 

Explanation : Answer is True.

It is possible to construct a unique binary tree. This is because the preorder traversal provides the root of the tree, and the inorder traversal helps determine the left and right subtrees.

Example 2

Input : 2 2

Output : false

Explanation : Two inorder traversals are insufficient to uniquely determine a binary tree.*/
class Solution{	
	public:	
		bool uniqueBinaryTree(int a, int b){
			// First of all we always need the preorder traversal to get the root of the tree then only can we see the next level so we get true if only 1 is there, 12 -> true, 13->true, But when post order nodes are stored in a stack we can get our unique tree
            // So 13, 12, 32, 23, but 22 XXX
            /*This is wrong the question says that by both the traversals we need unique{different trees}
            if(a == 2 && b == 2)return false;
            */
            /*This is also wrong The question says that after both the traversals should give the same tree
            if(a == b)return false;
            */
/*To replace long if
            if((a == 2 && (b == 1 || b == 3)) || ((a == 1 || a == 3) && b == 2))return true;
            */
            if(a == b)return false;
            return (a == 2 || b ==2);// One of them MUST be In-order (2)
            return false;
		}
};