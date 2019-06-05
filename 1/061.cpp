#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *p = head, *ret = NULL, *tail = NULL;
        int count = 0;
        while (p != NULL) {
            tail = p;
            p = p->next;
            count++;
        }

        if (count == 0 || count == 1 || k % count== 0)
            return head;
        k = count - k % count;

        if (ret == NULL) {
            ret = head;
            while (k > 1) {
               ret = ret->next;
               k--;
            }
            if (k == 1) {
                p = ret->next;
                ret->next = NULL;
                ret = p;
            }
        }

        if (ret == NULL)
            return head;

        tail->next = head;
        return ret;
    }
};

void test(int k) {
    ListNode nodes[5] {1,2,3,4,5};
    for (int i = 0; i < 4; i++) {
        nodes[i].next = &nodes[i+1];
    }

    Solution s;
    auto head = s.rotateRight(&nodes[0], k);
    int count = 0;
    while (head != NULL && count++ < 10) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

}

int main() {
    test(0);
    test(1);
    test(2);
    test(3);
    test(4);
    test(5);
    test(6);
  return 0;
}
