#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

void output(int data[], int size)
{
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", data[i]);
	}

	printf("\n");
}

int main(void) 
{
	int data[SIZE];
	int size = SIZE;
	int seed, num;
	int i, j;

	printf("Seed?=");
	scanf_s("%d", &seed);
	srand(seed);
	for (i = 0; i < size; i++) {
		data[i] = rand() % 100 + 1;
	}

	output(data, size);

	for (i = 0; i < size-1; i++) {
		for (j = size - 1; i < j; j--) {
			if (data[j] < data[j - 1]) {
				num = data[j - 1];
				data[j - 1] = data[j];
				data[j] = num;
			}
		}
	}

	output(data, size);

	return 0;
}
