#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main() {
	int input;

	printf("���ڸ� �Է����ּ���.\n");
	scanf("%d", &input);

	for (int i = 0; i < input; i++)
	{
		int num = i + 1;

		if (num % 3 == 0) {
			printf("X ");
		}
		else {
			printf("%d ", num);
		}
	}

	return 0;
}