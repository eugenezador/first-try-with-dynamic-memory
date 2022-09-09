#include <stdio.h>
#include <stdlib.h>

int array_value(int *n, int *m);

int dynamic_input(int **a, int m, int n);
void dynamic_optput(int **a, int m, int n);
void max(int **a, int n, int m);
void min(int **a, int n, int m);

int main() {
  int x;
  int n, m;

  if (array_value(&n, &m)) {
    printf("n/a");
  } else {
    int **a1 = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
      a1[i] = (int *)malloc(n * sizeof(int));

    if (dynamic_input(a1, n, m)) {
      printf("n/a");
    } else {
      dynamic_optput(a1, m, n);
      max(a1, n, m);
      min(a1, n, m);
    }
    for (int i = 0; i < n; i++) {
      free(a1[i]);
    }
    free(a1);
  }
  return 0;
}

int array_value(int *n, int *m) {
  int flag = 0;
  if (scanf("%d %d", n, m) == 2 && !(*n <= 0 && *n <= 0)) {
    flag = 0;
  } else {
    flag++;
  }
  return flag;
}

int dynamic_input(int **a, int m, int n) {
  int flag = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (scanf("%d", &a[i][j]) != 1) {
        flag++;
      }
    }
  }
  return flag;
}

void dynamic_optput(int **a, int m, int n) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d", a[i][j]);
      if (j != m - 1)
        printf("%c", ' ');
    }
    printf("\n");
  }
}

void max(int **a, int n, int m) {
  int max = a[0][0];
  int b[n];
  for (int i = 0; i < n; i++) {
    max = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][j] > max) {
        max = a[i][j];
      }
      b[i] = max;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", b[i]);
  }
}

void min(int **a, int n, int m) {
  int min = a[0][0];
  int b[m];
  for (int i = 0; i < m; i++) {
    min = 9999;
    for (int j = 0; j < n; j++) {
      if (a[j][i] < min) {
        min = a[i][j];
      }
      b[i] = min;
    }
  }

  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%d", b[i]);
    if (i < n - 1)
      printf(" ");
  }
}
