class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 边界判断
        if (0 == lists.size()) {
            return nullptr;
        }
        ListNode dummy(-1);
        ListNode* p = &dummy;
        // 比较类
        struct comparation
        {
            bool operator()(const ListNode* lhs, const ListNode* rhs){
                // 小顶堆
                return lhs->val > rhs->val;
            }
        };

        priority_queue<ListNode*, vector<ListNode*>, comparation> pque;
        // 元素放入优先级队列
        // 将 K 个链表的头结点加入小根堆, K 个升序的链表——各自已经升序
        for (auto& list : lists) {
            if (nullptr != list) { // 指针判空 // error 1:
                pque.emplace(list);
            }
        }

        // 堆顶元素出堆，接到 dummy后面
        // 出堆的链表的下一个结点入堆
        while (!pque.empty()) {
            ListNode* tmp = pque.top();
            pque.pop();

            p->next = tmp;
            if (tmp->next != nullptr) // 指针判空 error 2:
            {
                pque.emplace(tmp->next);
            }
            // p 指针不断前进         
            p = p->next;
        }

        return dummy.next;
    }
};