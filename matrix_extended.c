#include<stdio.h>
#include<stdlib.h>

/*
Calculate each row max and each col min.
Output calculated values after matrix output.
*/
#define ROWS_MAX 100
#define COLS_MAX 100

int allocation_choice(int* allocation_var_number);
int array_size(int* rows, int* cols);

void static_allocation_case(int static_array[ROWS_MAX][COLS_MAX], const int rows, const int cols, int** dynamic_array);
int static_array_input(int static_array[ROWS_MAX][COLS_MAX], const int rows, const int cols);
void static_array_output(int static_array[ROWS_MAX][COLS_MAX], const int rows, const int cols);

void static_array_to_dynamic(int static_array[ROWS_MAX][COLS_MAX], const int rows, const int cols, int** dynamic_array);

void dynamic_allocation_var_1(int** dynamic_array, const int rows, const int cols);
int** allocation_var_1(int** dynamic_array, const int rows, const int cols);
void free_var_1_allocation(int** dynamic_array, const int rows);

void dynamic_allocation_var_2(int** dynamic_array, int* array_value, const int rows, const int cols);
int** allocation_var_2(int** dynamic_array, int* array_value, const int rows, const int cols);
void free_var_2_allocation(int** dynamic_array, int* array_value);

void dynamic_allocation_var_3(int** dynamic_array, const int rows, const int cols);
int** allocation_var_3(int** dynamic_array, const int rows, const int cols);


int dynamic_array_input(int** dynamic_array, const int rows, const int cols);
void dynamic_array_output(int** dynamic_array, const int rows, const int cols);


void max_of_row(int** dynamic_array, const int rows, const int cols);
void min_of_col(int** dynamic_array, const int rows, const int cols);


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
				static_allocation_case(static_array, rows, cols, dynamic_array);
				break;
			case 2:
				dynamic_allocation_var_1(dynamic_array, rows, cols);
				break;
			case 3:
				dynamic_allocation_var_2(dynamic_array, array_value, rows, cols);
				break;
			case 4:
				dynamic_allocation_var_3(dynamic_array, rows, cols);
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


void static_allocation_case(int static_array[ROWS_MAX][COLS_MAX], const int rows, const int cols,
	int ** dynamic_array) {
	if (static_array_input(static_array, rows, cols)) {
		static_array_output(static_array, rows, cols);
		
		dynamic_array = allocation_var_3(dynamic_array, rows, cols);
		if (dynamic_array == NULL) {
			printf("Memory allocation error");
		}
		else {
			static_array_to_dynamic(static_array, rows, cols, dynamic_array);
			printf("\n");
			max_of_row(dynamic_array, rows, cols);
			printf("\n");
			min_of_col(dynamic_array, rows, cols);
			free(dynamic_array);
		}
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
		if (i != rows - 1) printf("\n");
	}
}

void static_array_to_dynamic(int static_array[ROWS_MAX][COLS_MAX], const int rows, const int cols,
	int** dynamic_array) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			dynamic_array[i][j] = static_array[i][j];
		}
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
			printf("\n");
			max_of_row(dynamic_array, rows, cols);
			printf("\n");
			min_of_col(dynamic_array, rows, cols);
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
			printf("\n");
			max_of_row(dynamic_array, rows, cols);
			printf("\n");
			min_of_col(dynamic_array, rows, cols);
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


void dynamic_allocation_var_3(int** dynamic_array, const int rows, const int cols) {

	dynamic_array = allocation_var_1(dynamic_array, rows, cols);

	if (dynamic_array == NULL) {
		printf("Allocation error");
	}
	else {

		if (dynamic_array_input(dynamic_array, rows, cols)) {
			dynamic_array_output(dynamic_array, rows, cols);
			printf("\n");
			max_of_row(dynamic_array, rows, cols);
			printf("\n");
			min_of_col(dynamic_array, rows, cols);
		}
		else {
			printf("Incorrect input of dynamic array");
		}

		free(dynamic_array);
	}
}
int** allocation_var_3(int** dynamic_array, const int rows, const int cols) {

	dynamic_array = (int**)malloc(rows * sizeof(int*) + rows * cols * sizeof(int));
	int* ptr = (int*)(dynamic_array + rows);

	for (int i = 0; i < rows; i++) {
		dynamic_array[i] = ptr + cols * i;
	}

	return dynamic_array;
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
		if(i != rows - 1) printf("\n");
	}
}

void max_of_row(int** dynamic_array, const int rows, const int cols) {
	int max = 0;
	for (int i = 0; i < rows; i++) {
		max = dynamic_array[i][0];
		for (int j = 1; j < cols; j++) {
			if (dynamic_array[i][j] > max) {
				max = dynamic_array[i][j];
			}
		}
		if (i != rows - 1) printf("%d ", max);
		else printf("%d", max);
	}
}

void min_of_col(int** dynamic_array, const int rows, const int cols) {
	int min = 0;
	for (int j = 0; j < cols; j++) {
		min = dynamic_array[0][j];
		for (int i = 1; i < rows; i++) {
			if (dynamic_array[j][i] < min) {
				min = dynamic_array[i][j];
			}
		}
		if (j != cols - 1) printf("%d ", min);
		else printf("%d", min);
	}
}

