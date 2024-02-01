#include <cstdio>
char ch[21] = "0123456789ABCDEFGHIJ";

void f1(int n, int k){
    if(n < k){
        printf("%X", n);
        return;
    }
    f1(n/k, k);
    printf("%X", n%k);
}

void f2(int n, int k){
    if(n > 0){
        f2(n/k, k);
        printf("%X", n%k);
    }
}

void f3(int n, int k){
    if(n > 0){
        f3(n/k, k);
        printf("%c", ch[n%k]);
    }
}

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
	//convert(30, 12);
	int n, k;
	while(1){
        scanf("%d %d", &n, &k);

        if(k > 20){
            printf("다시 입력해주세요!!");
        }else{
            break;
        }
	}
	/*
	n = 10;
	k = 2;
	*/

	if(n < 17){
        f1(n, k);
        printf("\n");
        f2(n, k);
        printf("\n");
	}
	f3(n, k);
	printf("\n");

	return 0;
}
