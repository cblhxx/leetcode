#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x = 0) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode guard(0), *tail;
        guard.next = head;
        head = &guard;

        for (int i = 0; i < m - 1; i++) {
            head = head->next;
        }
        tail = head->next;
        for (int i = 0; i < n - m; i++) {
            auto tmp = head->next;
            head->next = tail->next;
            tail->next = tail->next->next;
            head->next->next = tmp;
        }

        return guard.next;
    }
};

int main() {
    Solution s;
    ListNode nodes[5] {3,4};
    for (int i = 0; i < 1; i++) {
        nodes[i].next = &nodes[i+1];
    }
    auto p = s.reverseBetween(&nodes[0], 1, 2);
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;


  return 0;
}
