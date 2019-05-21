#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x = 0) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> ncache(n+1);
        ListNode *p = head;
        int i = 0;
        int idx = 0;
        while (p != NULL) {
            idx = i % (n + 1);
            ncache[idx] = p;
            p = p->next;
            i++;
        }
        if (i < n)
            return head;
        if (i == n)
            return head->next;
        idx = i % (n + 1);
        ncache[idx]->next = ncache[idx]->next->next;
        return head;
    }
};

int main() {
    int n = 5;
    ListNode nodes[n];// = {1,2,3,4,5};
    for (int i = 0; i < n; i++) {
        nodes[i].val = i + 1;
        if (i < n - 1)
            nodes[i].next = &nodes[i+1];
    }

    Solution s;
    auto head = s.removeNthFromEnd(nodes, 2);
    while (head != NULL) {
        cout << head->val;
        head = head->next;
    }
    cout << endl;


  return 0;
}
