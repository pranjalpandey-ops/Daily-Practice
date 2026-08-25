class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> v;

        while (head) {
            v.push_back(head->val);
            head = head->next;
        }

        sort(v.begin(), v.end());

        head = nullptr;
        ListNode* curr = nullptr;

        for (int x : v) {
            ListNode* node = new ListNode(x);

            if (!head) {
                head = node;
                curr = node;
            } else {
                curr->next = node;
                curr = node;
            }
        }

        return head;
    }
};
