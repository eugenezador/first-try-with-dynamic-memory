#include<stdio.h>
#include<stdlib.h>

#define ROWS_MAX 100
#define COLS_MAX 100

int allocation_choice(int* allocation_var_number);
int array_size(int* rows, int* cols);

void static_allocation_case(int static_array[ROWS_MAX][COLS_MAX], const int rows, const int cols);
int static_array_input(int static_array[ROWS_MAX][COLS_MAX], const int rows, const int cols);
void static_array_output(int static_array[ROWS_MAX][COLS_MAX], const int rows, const int cols);

void dynamic_allocation_var_1(int** dynamic_array, const int rows, const int cols);
int** allocation_var_1(int** dynamic_array, const int rows, const int cols);
void free_var_1_allocation(int** dynamic_array, const int rows);

void dynamic_allocation_var_2(int** dynamic_array, int* array_value, const int rows, const int cols);
int** allocation_var_2(int** dynamic_array, int* array_value, const int rows, const int cols);
void free_var_2_allocation(int** dynamic_array, int* array_value);


int dynamic_array_input(int** dynamic_array, const int rows, const int cols);
void dynamic_array_output(int** dynamic_array, const int rows, const int cols);

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
			int** dynamic_array = NULL;
			int* array_value = NULL;

			switch (allocation_var_number) {
			case 1:
				static_allocation_case(static_array, rows, cols);
				break;
			case 2:
				dynamic_allocation_var_1(dynamic_array, rows, cols);
				break;
			case 3:
				dynamic_allocation_var_2(dynamic_array, array_value, rows, cols);
				break;

			}
		}
	}

	return 0;
}

int allocation_choice(int* allocation_var_number) {
	int flag = 0;
	if (scanf("%d", allocation_var_number) == 1
		&& *allocation_var_number > 0
		&& *allocation_var_number < 5) {
		flag = 1;
	}
	return flag;
}

int array_size(int* rows, int* cols) {
	int flag = 0;
	if (scanf("%d %d", rows, cols) == 2 && *rows > 0 && *cols > 0) {
		flag = 1;
	}
	return flag;
}


void static_allocation_case(int static_array[ROWS_MAX][COLS_MAX], const int rows, const int cols) {
	if (static_array_input(static_array, rows, cols)) {
		static_array_output(static_array, rows, cols);
	}
	else {
		printf("Incorrect input of static array");
	}
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

void dynamic_allocation_var_1(int** dynamic_array, const int rows, const int cols) {

	dynamic_array = allocation_var_1(dynamic_array, rows, cols);

	if (dynamic_array == NULL) {
		printf("Allocation error");
	}
	else {

		if (dynamic_array_input(dynamic_array, rows, cols)) {
			dynamic_array_output(dynamic_array, rows, cols);
		}
		else {
			printf("Incorrect input of dynamic array");
		}

		free_var_1_allocation(dynamic_array, rows);
	}

}

int** allocation_var_1(int** dynamic_array, const int rows, const int cols) {
	dynamic_array = (int**)malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++) {
		dynamic_array[i] = (int*)malloc(cols * sizeof(int));
	}
	return dynamic_array;
}

void free_var_1_allocation(int** dynamic_array, const int rows) {
	for (int i = 0; i < rows; i++) {
		free(dynamic_array[i]);
	}
	free(dynamic_array);
}

void dynamic_allocation_var_2(int** dynamic_array, int* array_value, const int rows, const int cols) {
	
	dynamic_array = allocation_var_2(dynamic_array, array_value, rows, cols);

	if (dynamic_array == NULL) {
		printf("Allocation error");
	}
	else {

		if (dynamic_array_input(dynamic_array, rows, cols)) {
			dynamic_array_output(dynamic_array, rows, cols);
		}
		else {
			printf("Incorrect input of dynamic array");
		}

		free_var_2_allocation(dynamic_array, array_value);
	}

}

int** allocation_var_2(int** dynamic_array, int* array_value, const int rows, const int cols) {
	dynamic_array = (int**)malloc(rows * sizeof(int*));
	array_value = (int*)malloc(rows * cols * sizeof(int));

	for (int i = 0; i < rows; i++) {
		dynamic_array[i] = array_value + rows * i;
	}
	return dynamic_array;
}

void free_var_2_allocation(int** dynamic_array, int* array_value) {
	free(dynamic_array);
	free(array_value);
}




int dynamic_array_input(int** dynamic_array, const int rows, const int cols) {
	int flag = 1;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (!scanf("%d", &dynamic_array[i][j])) {
				flag = 0;
				break;
			}
		}
	}
	return flag;
}

void dynamic_array_output(int** dynamic_array, const int rows, const int cols) {
	for (int i = 0; i < rows; i++) {
		printf("%d", dynamic_array[i][0]);
		for (int j = 1; j < cols; j++) {
			printf(" %d", dynamic_array[i][j]);
		}
		printf("\n");
	}
}