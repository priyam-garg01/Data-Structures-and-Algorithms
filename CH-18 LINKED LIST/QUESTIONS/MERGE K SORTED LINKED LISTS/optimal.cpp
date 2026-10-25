/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // APPROACH USING RECURSION
        if(lists.size() == 0){
            return NULL;
        }
        
        /*Default priority queue is a max heap.You need a min heap because you want the smallest value first.*/
        // priority_queue<pair<int,ListNode*>> pq;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for(int i = 0; i < lists.size(); i++){//(n)
            if(lists[i] != NULL){
            pq.push({lists[i]->val, lists[i]});//takes log(n)
            }
        }
        
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(!pq.empty()){(n*m)
            pair<int, ListNode*> p = pq.top();
            temp->next = p.second;
            pq.pop();
            if(p.second->next){
                pq.push({p.second->next->val, p.second->next});
            }
            temp = temp->next;
        }
        return dummyNode->next;
    }
};/*
OPTIMAL : Using a priority queue we can store the head val and head node of each linked list and then store it in a new list in correct order
T.C. = O(NLOGN + N*M{WHILE LOOP}*3LOGN{3operations in loop})
T.C. = O(3*N*M*LOGN), S.C. = O(N)
n = number of lists and m = number of elements in each list*/