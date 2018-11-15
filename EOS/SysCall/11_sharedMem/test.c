#include <stdio.h>
#define val int*
void main(int argc, char const *argv[]) {
  val p1,p2;

  printf("%d\n",sizeof(p1));
  printf("%d\n",sizeof(p2));
  return 0;
}
