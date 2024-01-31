#include <cstdio>

void convert(int number, int sinbab)
{
	if (number == 0)
		return;

	convert(number/sinbab, sinbab);

	if (number % sinbab >= 10)
		printf("%c", 'A' + number % sinbab - 10); // X�� 10���� ū ��츦 ó���ϱ� ���ؼ�
	else
		printf("%d", number % sinbab);
}

int main()
{
	convert(30, 12);
}
