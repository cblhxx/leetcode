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
    ListNode* deleteDuplicates(ListNode* _head) {
        if (_head == NULL)
            return NULL;
        ListNode head(0), *left = NULL, *right = NULL;
        head.next = _head;
        left = &head;
        right = _head->next;
        int v = _head->val;

        while (right != NULL) {
            if (right->val != v) {
                v = right->val;
                right = right->next;
                left = left->next;
                continue;
            }
            while (right != NULL && right->val == v) {
                right = right->next;
            }
            left->next = right;
            if (right != NULL) {
                v = right->val;
                right = right->next;
            }
        }
        return head.next;

    }
};



int main() {
    Solution s;
    vector<ListNode> nodes {1,2,3,3,4,4,5};

    for (int i = 0; i < nodes.size() - 1; i++) {
        nodes[i].next = &nodes[i+1];
    }

    auto head = s.deleteDuplicates(&nodes[0]);
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;


  return 0;
}
