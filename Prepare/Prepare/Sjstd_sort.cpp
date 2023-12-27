#include <cstdio>
#include <algorithm>

struct DATA
{
	int x;
	int y;
} ss[5] = { {33,1}, {22,3}, {11,2}, {33,5}, {55,4} };

int n = 10, data[10] = { 2,6,3,7,5,0,9,8,1,4 };

void ArrayPrn() {
	for (int i = 0; i < n; i++)
	{
		printf("%d", data[i]);
	}
	printf("\n");
}

void DataPrn() {
	for (int i = 0; i < 5; i++)
	{
		printf("%d,%d \t", ss[i].x, ss[i].y);
	}
	printf("\n");
}

bool Asc(int left, int right) {
	return left < right;
}

bool Desc(int left, int right) {
	return left > right;
}

bool AscData(DATA left, DATA right) {
	return left.x < right.x;
}

bool AscData2(DATA left, DATA right) {
	if (left.x == right.x)
		return left.y > right.y;
	else
		return left.x < right.x;
}

int main() {
	printf("sort Àü \t: ");
	ArrayPrn();
	std::sort(data, data + n, Desc);
	printf("Desc sort ÈÄ \t: ");
	ArrayPrn();
	std::sort(data, data + n, Asc);
	printf("Asc sort ÈÄ \t: ");
	ArrayPrn();
	std::sort(ss, ss + 5, AscData);
	DataPrn();
	std::sort(ss, ss + 5, AscData2);
	DataPrn();
	return 0;
}