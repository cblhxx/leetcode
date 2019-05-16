#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
  int __reverse(int x, int64_t* v) {
    if (x / 10 == 0) {
      *v = x;
      return 1;
    }
    auto len = __reverse(x / 10, v);
    *v += (x % 10) * pow(10, len++);

    return len;
  }
    int reverse(int x) {
      int64_t v;
      __reverse(x, &v);
      if (int(v) == v)
        return v;
      return 0;
    }
};

int main() {
  Solution s;
  cout << s.reverse(123) << endl;
  cout << s.reverse(-123) << endl;
  cout << s.reverse(120) << endl;


  return 0;
}
