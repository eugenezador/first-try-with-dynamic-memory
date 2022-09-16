#include<stdio.h>
#include<stdlib.h>

#define ROWS_MAX 100
#define COLS_MAX 100

int allocation_choice(int* allocation_var_number);
int array_size(int* rows, int* cols);

void static_allocation_case(int static_array[ROWS_MAX][COLS_MAX], const int rows, const int cols);
int static_array_input(int static_array[ROWS_MAX][COLS_MAX], const int rows, const int cols);
void static_array_output(int static_array[ROWS_MAX][COLS_MAX], const int rows, const int cols);

int main() {
	int allocation_var_number;
	if (!allocation_choice(&allocation_var_number)) {
		printf("Incorrect allocation number");
	}
	else {
		int rows, cols;
		if (!array_size(&rows, &cols)) {
			printf("Incorrect array size input");
		}
		else {
			int static_array[ROWS_MAX][COLS_MAX];

			switch (allocation_var_number) {
			case 1:
				static_allocation_case(static_array, rows, cols);
			//case 2:

			}
		}
	}

	return 0;
}

int allocation_choice(int* allocation_var_number) {
	int flag = 1;
	if (scanf("%d", allocation_var_number) != 1
		&& *allocation_var_number > 0
		&& *allocation_var_number < 5) {
		flag = 0;
	}
	return flag;
}

int array_size(int* rows, int* cols) {
	int flag = 1;
	if (scanf("%d %d", rows, cols) != 2 && *rows <= 0 && *cols <= 0) {
		flag = 0;
	}
	return flag;
}


void static_allocation_case(int static_array[ROWS_MAX][COLS_MAX], const int rows, const int cols) {
	static_array_input(static_array, rows, cols);
	static_array_output(static_array, rows, cols);
}
int static_array_input(int static_array[ROWS_MAX][COLS_MAX], const int rows, const int cols) {
	int flag = 1;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (!scanf("%d", &static_array[i][j])) {
				flag = 0;
				break;
			}
		}
	}
	return flag;
}
void static_array_output(int static_array[ROWS_MAX][COLS_MAX], const int rows, const int cols) {
	for (int i = 0; i < rows; i++) {
		printf("%d", static_array[i][0]);
		for (int j = 1; j < cols; j++) {
			printf(" %d", static_array[i][j]);
		}
		printf("\n");
	}
}
