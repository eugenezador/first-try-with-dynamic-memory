#include <stdio.h>
#include <stdlib.h>

//#include <crtdbg.h>// for leak detecting in Win

int array_size(size_t* size);
int* memory_allocation(size_t size);
int input(int* array, size_t size);
void output(int* array, size_t size);
void swap(int* a, int* b);
int partition(int* array, int low, int high);
void quick_sort(int* array, int low, int high);

int main() {
    size_t size;
    if (!array_size(&size)) {
        printf("n/a");
    }
    else {
        int* array = memory_allocation(size);
        if (array == NULL) {
            printf("n/a");
        }
        else {
            if (input(array, size)) {
                quick_sort(array, 0, size - 1);
                output(array, size);
            }
            else {
                printf("n/a");
            }

            free(array);
        }
    }

    //_CrtDumpMemoryLeaks();//for report leak detecting in Win
    return 0;
}

int array_size(size_t* size) {
    int f = 1;
    if (!scanf("%ld", size) && *size <= 0) {
        f = 0;
    }
    return f;
}

int* memory_allocation(size_t size) {
    return (int*)malloc(size * sizeof(int));
}

int input(int* array, size_t size) {
    int f = 1;
    for (size_t i = 0; i < size; i++) {
        if (!scanf("%d", array++)) {
            f = 0;
        }
    }
    return f;
}

void output(int* array, size_t size) {
    printf("%d", array[0]);
    for (size_t i = 1; i < size; i++) {
        printf(" %d", array[i]);
    }
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int* array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);
    return i + 1;
}

void quick_sort(int* array, int low, int high) {
    if (low < high) {
        int pivot = partition(array, low, high);

        quick_sort(array, low, pivot - 1);
        quick_sort(array, pivot + 1, high);
    }
}
