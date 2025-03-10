 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
   //solution1: time complexity O(m*n)
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* current = headA;
        ListNode* current2 = headB;

        while (current) {
            while (current2 != NULL && current2 != current) {
                current2 = current2->next;
            }
            if (current2) {
                cout << "Intersected at " << current2->val << endl;
                return current2;
            }
            current2 = headB;
            current = current->next;
        }
        return NULL;
    }
};
  //solution2: time complexity O(m + n)
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return nullptr;

    ListNode* p1 = headA;
    ListNode* p2 = headB;

    while (p1 != p2) {  // 两个指针在相交点相遇，或者同时为 nullptr
        p1 = p1 ? p1->next : headB;  // 走完 headA，就跳到 headB
        p2 = p2 ? p2->next : headA;  // 走完 headB，就跳到 headA
    }

    return p1;  // 这里要么是交点，要么是 nullptr（无交点）
}
* Note: It works because after one search, A and B come to the points of departure of the same length.
