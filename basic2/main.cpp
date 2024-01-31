#include <cstdio>

void convert(int number, int sinbab)
{
	if (number == 0)
		return;

	convert(number/sinbab, sinbab);

	if (number % sinbab >= 10)
		printf("%c", 'A' + number % sinbab - 10); // X가 10보다 큰 경우를 처리하기 위해서
	else
		printf("%d", number % sinbab);
}

int main()
{
	convert(30, 12);
}
