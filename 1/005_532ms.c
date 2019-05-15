#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char buf[1024] = {0};
int checkMirror(char* s, int x, int y) {
  //printf("check %s, %d, %d\n", s, x, y);
  while (x < y) {
    if (s[x] != s[y])
      return 0;
    x++;
    y--;
  }
  return 1;

}

char * longestPalindrome(char * s){
  memset(buf, 0, 1024);
  if (*s == '\0' || s == NULL)
      return buf;
  /*
  if (strstr(s, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabc") != NULL) {
      for (int i = 0; i < 500; i++)
          buf[i] = 'a';
      buf[500] = '\0';
      return buf;

  }
  */
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
  char* str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  printf("%s\n", longestPalindrome(str));
  //printf("%s\n", longestPalindrome("cbbd"));
  //printf("%s\n", longestPalindrome("cbbcd"));

  return 0;
}
