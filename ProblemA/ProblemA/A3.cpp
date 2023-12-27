#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

int size;
int cur;
int data[1000000];
int find;

void read() {
	FILE* inf;

	if ((fopen_s(&inf, "input.txt", "r")) != 0)
	{
		printf("파일 오픈 실패\n");
		exit(0);
	}

	fscanf(inf, "%d\n", &size);
	for (int i = 0; i < size; i++)
	{
		fscanf(inf, "%d ", &data[i]);
	}
	fscanf(inf, "\n%d", &find);

	fclose(inf);
}

void write() {
	FILE* outf;

	if ((fopen_s(&outf, "output.txt", "w")) != 0)
	{
		printf("파일 오픈 실패\n");
		exit(0);
	}

	fprintf(outf, "\n%d\n", cur);

	fclose(outf);
}

int binary(int low, int high) {
	int mid;
	while (low <= high) 
	{
		mid = (low + high) / 2;
		if (data[mid] == find)
			return (mid + 1);
		else if (data[mid] > find)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

int binary2(int low, int high) {
	int mid;

	if (low > high) {
		return -1;
	}

	mid = (low + high) / 2;

	if (data[mid] == find) {
		return (mid + 1);
	}
	else if (data[mid] > find)
	{
		high = mid - 1;
		return binary2(low, high);
	}
	else {
		low = mid + 1;
		return binary2(low, high);
	}
}

int main() {
	/*read();*/
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d ", &data[i]);
	}
	scanf("%d", &find);
	cur = binary2(0, size - 1);
	printf("\n%d\n", cur);
	/*write();*/
	return 0;
}