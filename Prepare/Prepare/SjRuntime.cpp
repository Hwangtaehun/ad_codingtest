#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <algorithm>

int n, data[100000];

void swap(int a, int b);
void SelectionSort(void);
void QuickSort(int s, int e);

int main() {
	srand((unsigned int)time(NULL));
	printf("자료 수 입력 : ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		data[i] = rand();
	}

	int start = clock();
	printf("start tiem() \t = %d\n", (unsigned int)time(NULL));
	printf("start clock()\t = %d\n", start);

	/*SelectionSort();*/
	/*QuickSort(0, n - 1);*/
	std::sort(data, data + n);

	/*Sleep(1000);*/
	printf("result     \t=%lf(sec)\n", (double)(clock() - start) / CLOCKS_PER_SEC);
	printf("end colck()\t=%d\n", clock());
	printf("end time() \t=%d\n", (unsigned int)time(NULL));

	return 0;
}

void swap(int a, int b) {
	int temp;
	temp = data[a];
	data[a] = data[b];
	data[b] = temp;
}

void SelectionSort() {
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (data[i] > data[j]) {
				swap(i, j);
			}
		}
	}
}

void QuickSort(int s, int e) {
	if (s < e) {
		int p = s, l = s + 1, r = e;
		while (l <= r)
		{
			while (l <= e && data[l] <= data[p])
			{
				l++;
			}
			while (r > s + 1 && data[r] >= data[p])
			{
				r--;
			}
			if (l < r) {
				swap(l, r);
			}
		}
		swap(p, r);
		QuickSort(s, r - 1);
		QuickSort(r + 1, e);
	}
}