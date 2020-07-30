#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define ARRAY_LENGTH 5

void merge(int *arr, int p, int q, int r);
void merge_sort(int *arr, int p, int r);
void draw_array(int *arr, int size);

int main(int argc, char *argv[]) {
	int i, arr[ARRAY_LENGTH];

	srand(time(NULL));

	for (i = 0; i < ARRAY_LENGTH; i++)
		arr[i] = rand() % 100;

	draw_array(arr, ARRAY_LENGTH);
	merge_sort(arr, 0, ARRAY_LENGTH - 1);
	draw_array(arr, ARRAY_LENGTH);

	exit(0);
}

void draw_array(int *arr, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d", arr[i]);
		if (i != size - 1) {
			printf(", ");
		}
		else {
			printf("\n");
		}
	}
}

void merge_sort(int *arr, int p, int r) {
	int m;

	if (p < r) {
		m = (p + r) / 2;
		merge_sort(arr, p, m);
		merge_sort(arr, m + 1, r);

		merge(arr, p, m, r);
	}
}

/**
 * p <= q < r
 * (p, q, r) = (8, 11, 15);
 */
void merge(int *arr, int p, int q, int r) {
	int n1 = q - p + 1; // 4
	int n2 = r - q; // 4
	int *l_arr = calloc(n1 + 1, sizeof(int));
	int *r_arr = calloc(n2 + 1, sizeof(int)); 
	int i, j, k;

	for (i = 0; i < n1; i++) // 0 <= i < 4
		l_arr[i] = arr[p + i]; // 8 <= p + i < 12

	for (j = 0; j < n2; j++) // 0 <= j < 4
		r_arr[j] = arr[q + j + 1]; // 12 <= q + j + 1 < 16

	l_arr[n1] = r_arr[n2] = INT_MAX;
	i = j = 0;

	for (k = p; k <= r; k++) { // 8 <= k < 15
		if (l_arr[i] <= r_arr[j]) {
			arr[k] = l_arr[i];
			i++;
		}
		else {
			arr[k] = r_arr[j];
			j++;
		}
	}

	free(l_arr);
	free(r_arr);
}