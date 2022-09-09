#include <stdio.h>
#include <stdlib.h>

int main () {
    int *a;  // указатель на массив
      int i, n;

      printf("Введите размер массива: ");
      scanf("%d", &n);
      // Выделение памяти
      a = (int*)calloc(n, sizeof(int));
      // Ввод элементов массива
      for (i = 0; i<n; i++)
      {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
      }
      // Вывод элементов массива
      for (i = 0; i<n; i++)
        printf("%d ", a[i]);
      free(a);
      getchar();   getchar();
      return 0;
}
       

