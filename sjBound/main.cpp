#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, key;
int data[1000000];

void write()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &data[i]);
    }
    scanf("%d", &key);
}

int main()
{
    write();

    printf("\n%d\n", std::binary_search(data, data+n, key));
    printf("%d\n", data);
    printf("lower_bound의 값 출력\n");
    printf("%d\n", std::lower_bound(data, data+n, key));
    printf("%d\n", std::lower_bound(data, data+n, key) - data + 1);

    printf("upper_bound의 값 출력\n");
    printf("%d\n", std::upper_bound(data, data+n, key));
    printf("%d\n", std::upper_bound(data, data+n, key) - data + 1);

    return 0;
}
