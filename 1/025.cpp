#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode node(0);
        node.next = head;
        ListNode *p = &node;
        ListNode *q = &node;

        int idx = 0;
        int length = 0;
        if (k == 1)
            return head;

        while (head != NULL) {
            length++;
            head = head->next;
        }

        while (q->next != NULL) {
            if (idx % k == 0) {
                if (idx + k > length)
                    break;
                p = q;
                q = q->next;
                idx++;
                continue;
            }
            ListNode *target = q->next;
            q->next = target->next;
            target->next = p->next;
            p->next = target;
            idx++;
        }
        return node.next;
    }
};

int main() {
    ListNode nodes[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    for (int i = 0; i < 4; i++) {
        nodes[i].next = &nodes[i+1];
    }
    Solution s;
    ListNode *p = s.reverseKGroup(&nodes[0], 3);
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;


  return 0;
}
