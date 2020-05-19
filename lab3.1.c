#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<windows.h>
#include<locale.h>
#include<stdlib.h>




int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "RUS");

	int len = 0, v, i, n = 0;


	FILE* input = fopen("INPUT.txt", "r");
	FILE* output_odd = fopen("ODD.txt", "w");
	FILE* output_even = fopen("EVEN.TXT", "w");

	if (input == NULL) {
		printf("Нельзя создать файл");
		return 1;
	}

	while (fscanf(input, "%d", &v) != EOF) {
		n++;
	}
	printf("Количество чисел в файле: %d\n", n);
	int* A = (int*)malloc(n * sizeof(int));
	if (len == n) {
		n *= 2;
		A = (int*)realloc(A, n * sizeof(int));

		if (A == NULL) {
			printf("Плохое распределение");
			return 1;
		}
	}
	rewind(input);


	for (i = 0; i < n; ++i) {
		fscanf(input, " %d", &A[i]);
		if (A[i] % 2 == 0) {
			fprintf(output_even, "%d ", A[i]);
		}

		else if (A[i] % 2 != 0) {
			fprintf(output_odd, "%d ", A[i]);
		}

		printf(" %d", A[i]);

	}
	free(A);
	printf(" - Числа которые были в файле INPUT \n");

	fclose(input);
	fclose(output_odd);
	fclose(output_even);
	system("PAUSE");
	return 0;
}