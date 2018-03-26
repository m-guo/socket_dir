#include <stdio.h>
#include <string.h>

struct prtout {
  int id;
  char des[10];
};
#define lenPT sizeof(struct prtout)

int main()
{
  int i;
  char txt[10] = {0};

  struct prtout putout[5];
  for(i = 0; i <5; i++) {
    memset(&putout[i], 0, lenPT);
    putout[i].id = i+1;
    sprintf(txt, "Value %d", i);
    memcpy(putout[i].des, txt, strlen(txt));
  }

  for(i = 0; i < 5; i++) {
    printf("PutOut id %d\n", putout[i].id);
    printf("Des is %s\n", putout[i].des);
  }
  return 0;
}
