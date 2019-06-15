#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* p) {
        if (p == NULL)
            return p;

        ListNode head(0), *tail;
        head.next = p;
        tail = p->next;

        while (tail != NULL) {
            while (tail != NULL && p->val == tail->val)
                tail = tail->next;
            p->next = tail;
            p = tail;
            if (tail != NULL)
                tail = tail->next;

        }

        return head.next;
    }
};

int main() {
    vector<ListNode> nodes {1,1,2,3,3,4,5,5,6};
    for (int i = 0; i < nodes.size() - 1; i++) {
        nodes[i].next = &nodes[i+1];
    }
    Solution s;
    auto head = s.deleteDuplicates(&nodes[0]);
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;


  return 0;
}
