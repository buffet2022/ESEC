class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        int n = lists.size();
        if (n == 1) {
            return lists[0];
        }

        return mergeTwoLists(mergeKLists(vector<ListNode*>(lists.begin(), lists.begin() + n / 2)),
                             mergeKLists(vector<ListNode*>(lists.begin() + n / 2, lists.end())));
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        p->next = l1 ? l1 : l2;

        return dummy->next;
    }
};