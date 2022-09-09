#include <stdio.h>
#include <stdlib.h>
#define NMAX 100
#define MMAX 100

int number(int *n);
int array_value(int *n, int *m);

int dynamic_input(int **a, int m, int n);
void dynamic_optput(int **a, int m, int n);

int main() {
  int x;
  int n, m;

  if (number(&x)) {
    printf("n/a");
  } else {
    if (array_value(&n, &m)) {
      printf("n/a");
    } else {
      if (x == 1) {
        int **a1 = (int **)malloc(m * sizeof(int *));
        for (int i = 0; i < m; i++)
          a1[i] = (int *)malloc(n * sizeof(int));

        int a[NMAX][MMAX];
        int *copy[MMAX];
        for (int i = 0; i < m; i++)
          copy[i] = a[i];
        a1 = copy;

        if (dynamic_input(a1, n, m)) {
          printf("n/a");
        } else {
          dynamic_optput(a1, n, m);
        }
        for (int i = 0; i < n; i++) {
          free(a1[i]);
        }
        free(a1);
      } else if (x == 2) {
        int **a2 = (int **)malloc(m * sizeof(int *));
        for (int i = 0; i < m; i++)
          a2[i] = (int *)malloc(n * sizeof(int));

        if (dynamic_input(a2, n, m)) {
          printf("n/a");
        } else {
          dynamic_optput(a2, m, n);
        }
        for (int i = 0; i < n; i++) {
          free(a2[i]);
        }
        free(a2);

      } else if (x == 3) {
        int **p_a = malloc(m * sizeof(int *));
        int *v_a = malloc(m * n * sizeof(int));
        for (int i = 0; i < m; i++)
          p_a[i] = v_a + n * i;

        if (dynamic_input(p_a, n, m)) {
          printf("n/a");
        } else {
          dynamic_optput(p_a, m, n);
        }

        free(p_a);
        free(v_a);
      } else if (x == 4) {
        int **single_matr = malloc(m * n * sizeof(int) + m * sizeof(int *));
        int *p = (int *)(single_matr + m);

        for (int i = 0; i < m; i++) {
          single_matr[i] = p + n * i;
        }

        if (dynamic_input(single_matr, n, m)) {
          printf("n/a");
        } else {
          dynamic_optput(single_matr, m, n);
        }

        free(single_matr);
      }
    }
  }
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
