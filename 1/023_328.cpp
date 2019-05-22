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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head(0);
        ListNode *p = &head;
        for (int i = 0; i < lists.size(); ) {
            if (lists[i] == NULL) {
                lists.erase(lists.begin());
                continue;
            }
            i++;
        }
        if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return lists[0];

        while (lists.size() > 0) {
            int m = 0;
            ListNode* q = lists[0];
            for (int i = 1; i < lists.size(); i++) {
                if (lists[i]->val < q->val) {
                    m = i;
                    q = lists[i];
                }
            }
            //cout << q->val << endl;
            if (q != NULL) {
                p->next = q;
                lists[m] = q->next;
                p = q;
                p->next = NULL;
            }

            if (lists[m] == NULL) {
                //cout << "erase:" << m << endl;
                lists.erase(lists.begin() + m);
                continue;
            }
        }
        return head.next;
    }
};


int main() {
    ListNode nodes[8] = {1, 4, 5, 1, 3, 4, 2, 6};
    for (int i = 0; i < 7; i++) {
        nodes[i].next = &nodes[i+1];
    }
    nodes[2].next = NULL;
    nodes[5].next = NULL;

    Solution s;

    vector<ListNode*> lists;
    lists.push_back(&nodes[0]);
    lists.push_back(&nodes[3]);
    //lists.push_back(&nodes[6]);
    ListNode *p = s.mergeKLists(lists);
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;


  return 0;
}
