#include <stdio.h>
#include <stdlib.h>

int number(int *n);
int *allocate(int *a, int n, int *f);
int input(int *a, int n);
void sort(int *a, int n);
void output(int *a, int n);

int main() {
  int *a;
  int n;
  int flag = 0;
  if (number(&n)) {
    printf("n/a");
  } else {
    a = allocate(a, n, &flag);
    if (flag != 0)
      printf("n/a");
    // a = (int*) calloc(n, sizeof(int));
    // if(NULL == a){
    //     printf("n/a");
    // }

    if (input(a, n)) {
      printf("n/a");
    } else {
      sort(a, n);
      output(a, n);
    }
  }
    free(a);
  return 0;
}

int number(int *n) {
  int flag = 0;
  char c;
  if (scanf("%d%c", n, &c) == 2 && c == '\n') {
    if (*n <= 0) {
      flag++;
    }
  }
  return flag;
}

int *allocate(int *a, int n, int *f) {
  a = (int *)calloc(n, sizeof(int));
  if (NULL == a) {
    f++;
  }
  return a;
}

int input(int *a, int n) {
  char c;
  for (int i = 0; i < n; i++) {
    if (scanf("%d%c", a + i, &c) != 2)
      return 1;
    if (c != ' ' && c != '\n') {
      return 1;
    }
  }
  return 0;
}

void sort(int *a, int n) {
  int temp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
}

void output(int *a, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d", a[i]);
    if (i != n - 1)
      printf("%c", ' ');
  }
}
