#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

int32_t compare(const void* a, const void* b) {
  return (*(int32_t*)a - *(int32_t*)b);
}

int main(void) {
  char buf[128];
  const char* FILENAME = "./input.txt";
  const uint32_t NUMLINES = 1000;
  FILE *file = fopen(FILENAME, "r");

  int32_t list1[NUMLINES]; 
  int32_t  list2[NUMLINES];

  if (file == NULL) {
    printf("Could not open file!\n");
    return 1;
  }
    
  int32_t count = 0;
  while(fgets(buf, sizeof(buf), file)) {
    sscanf(buf, "%d %d", &list1[count], &list2[count]);
    count++;
  }

  fclose(file);

  qsort(list1, NUMLINES, sizeof(int32_t), compare);
  qsort(list2, NUMLINES, sizeof(int32_t), compare);

  int32_t diff = 0;
  for (int i = 0; i < NUMLINES; i++) {
    diff += abs(list2[i] - list1[i]);
  }

  printf("%d\n", diff);

  return 0;
}
