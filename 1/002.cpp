#include <iostream>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
  int addOnce(const ListNode* n1, const ListNode* n2, int addition, ListNode* out) {
    int v1 = 0;
    int v2 = 0;
    if (n1 != NULL) {
      v1 = n1->val;
    }
    if (n2 != NULL) {
      v2 = n2->val;
    }

    auto val = v1 + v2 + addition;
    out->val = val % 10;
    return val / 10;
  }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode guard(0);
      ListNode *tail = &guard;
      int addition = 0;
      while (l1 != NULL || l2 != NULL || addition > 0) {
        //std::cout << "a";
        auto node = new ListNode(0);
        tail->next = node;
        tail = node;
        addition = addOnce(l1, l2, addition, node);
        if (l1 != NULL)
          l1 = l1->next;
        if (l2 != NULL)
          l2 = l2->next;
      }
      return guard.next;
    }
};

int main() {
  //ListNode l1[3]{2, 4, 3};
  //auto l1 = new ListNode[3]{2, 4, 3};
  //auto l2 = new ListNode[3]{5, 6, 4};
  //l1[0].next = &l1[1];
  //l1[1].next = &l1[2];
  //l2[0].next = &l2[1];
  //l2[1].next = &l2[2];

  auto l1 = new ListNode[2]{1, 8};
  auto l2 = new ListNode[1]{0};
  l1[0].next = &l1[1];

  Solution s;
  auto l3 = s.addTwoNumbers(l1, l2);
  while (l3 != NULL) {
    std::cout << l3->val << " ";
    l3 = l3->next;
  }
  std::cout << endl;


  //l1->next = 

  return 0;
}
