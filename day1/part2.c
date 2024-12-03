#include <stdint.h>
#include <stdio.h>

int main(void) {
  char buf[128];
  const char* FILENAME = "input.txt";
  const uint32_t NUMLINES = 1000;
  FILE *file = fopen(FILENAME, "r");

  int32_t list1[NUMLINES]; 
  int32_t list2[NUMLINES];

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

  int32_t score = 0;
  int32_t curr;
  int32_t ocurr;
  for (int i = 0; i < NUMLINES; i++) {
    curr = list1[i];
    ocurr = 0;
    for (int j = 0; j < NUMLINES; j++) {
      if (curr == list2[j]) {
        ocurr++;
      }
    }

    score += (curr * ocurr);
  }

  printf("%d\n", score);

  return 0;
}
