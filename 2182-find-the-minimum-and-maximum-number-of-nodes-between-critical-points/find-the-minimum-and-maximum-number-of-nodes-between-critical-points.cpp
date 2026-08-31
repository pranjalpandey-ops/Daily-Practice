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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1, last = -1, min = -1, i = 1;
        ListNode *p = head, *c = head->next;

        while (c->next != nullptr) {
            if ((c->val > p->val && c->val > c->next->val) || 
                (c->val < p->val && c->val < c->next->val)) {
                
                if (first == -1) {
                    first = i;
                } else {
                    int dist = i - last;
                    min = (min == -1) ? dist : std::min(min, dist);
                }
                last = i;
            }
            p = c;
            c = c->next;
            i++;
        }

        return {min, (min == -1) ? -1 : last - first};
    }
};