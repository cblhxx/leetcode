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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *p, *q;
        p = head;
        head = p->next;
        q = this->swapPairs(head->next);
        head->next = p;
        p->next = q;
        return head;
    }
};

int main() {
    ListNode nodes[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    for (int i = 0; i < 7; i++) {
        nodes[i].next = &nodes[i+1];
    }
    Solution s;
    ListNode *p = s.swapPairs(&nodes[0]);
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;


  return 0;
}
