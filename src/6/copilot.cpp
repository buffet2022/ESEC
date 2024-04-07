class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }

private:
    ListNode* merge(vector<ListNode*>& lists, int left, int right) {
        if (left == right) {
            return lists[left];
        }
        if (left > right) {
            return nullptr;
        }
        int mid = left + (right - left) / 2;
        ListNode* leftList = merge(lists, left, mid);
        ListNode* rightList = merge(lists, mid + 1, right);
        return mergeTwoLists(leftList, rightList);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if (l1) {
            curr->next = l1;
        }
        if (l2) {
            curr->next = l2;
        }
        return dummy.next;
    }
};
