#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#define ARR_SIZE 9

int data[ARR_SIZE];
int bigest = 0;
int cur;

void read() {
	FILE* inf;

	if ((fopen_s(&inf, "input.txt", "r")) != 0)
	{
		printf("파일 오픈 실패\n");
		exit(0);
	}

	for (int i = 0; i < ARR_SIZE; i++)
	{
		fscanf(inf, "%d\n", &data[i]);
	}

	fclose(inf);
}

void write() {
	FILE* outf;

	if ((fopen_s(&outf, "output.txt", "w")) != 0)
	{
		printf("파일 오픈 실패\n");
		exit(0);
	}

	fprintf(outf, "%d\n%d\n", bigest, cur);

	fclose(outf);
}

void solve() {
	for (int i = 0; i < ARR_SIZE - 1; i++)
	{
		if (bigest < data[i]) {
			bigest = data[i];
			cur = i + 1;
		}
	}
}

int main() {
	read();
	solve();
	write();
	return 0;
}