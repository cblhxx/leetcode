#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buf[1024] = {0};
int dp[1024][1024] = {0};

int checkMirror(char* s, int i, int j) {
  //printf("check %s, %d, %d\n", s, x, y);
  int x = i, y = j;
  while (x < y) {
    if (s[x] != s[y] || dp[x][y] == -1) {
      dp[x][y] = -1;
      return 0;
    }
    dp[x][y] = -1;
    x++;
    y--;
  }
  return 1;

}

char * longestPalindrome(char * s){
  memset(buf, 0, 1024);
  memset(dp, 0, 1024 * 1024 * sizeof(int));
  if (*s == '\0' || s == NULL)
      return buf;

  int len = strlen(s);
  int l = len;
  while (l >= 2) {
    for (int i = 0; i < len - l + 1; i++) {
      int j = i + l - 1;
      if (checkMirror(s, i, j)) {
        strncpy(buf, s+i, l);
        buf[l] = '\0';
        return buf;
      }
    }
    l--;
  }
  buf[0] = s[0];
  return buf;
}

int main() {
  printf("%s\n", longestPalindrome("babad"));

  return 0;
}
