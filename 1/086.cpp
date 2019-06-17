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
    ListNode* partition(ListNode* head, int x) {
        ListNode node0{0}, node1{0};
        ListNode *curr = &node0, *tail_back = &node1;
        node0.next = head;

        while (curr->next != NULL) {
            if (curr->next->val >= x) {
                tail_back->next = curr->next;
                tail_back = tail_back->next;
                curr->next = curr->next->next;
            }
            else {
                curr = curr->next;
            }
        }
        tail_back->next = NULL;
        curr->next = node1.next;

        return node0.next;
    }
};

int main() {
    Solution s;
    ListNode nodes[6] {1,4,3,2,5,2};
    //ListNode nodes[6] {1,1,2,2,1,2};
    for (int i = 0; i < 5; i++) {
        nodes[i].next = &nodes[i+1];
    }

    ListNode *head = &nodes[0];
    head = s.partition(head, 3);
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;


  return 0;
}
