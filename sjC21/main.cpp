#include <cstdio>
#include <algorithm>

int data[16], separate;
int cnt, person, end;
int cho[16] = {0,}, number = 0;

//solve
int gift[20], g1, g2, g3, n, d = 0x0fffffff, gd = 0x0fffffff;

void ArrayPrn(){
    for(int i = 0; i < n; i++){
        printf("%d ", gift[i]);
    }
    printf("\n");
}

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &gift[i]);
    }
}

bool Desc(int left, int right){
    return left > right;
}

void Solve(int no, int a, int b, int c){
    if(no < n){
        Solve(no + 1, a, b, c+gift[no]);
        Solve(no + 1, a, b+gift[no], c);
        Solve(no + 1, a+gift[no], b, c);
    }else if(a >= b && b >= c && d >= (a-c) && gd > a){
        g1 = a, g2 = b, g3 = c;
        d = a - c;
        gd = a;
        printf("%d %d %d %d\n", g1, g2, g3, d);
    }
}

void In(){
    freopen("input.txt", "r", stdin);

    scanf("%d", &cnt);
    for(int i = 1; i <= cnt; i++){
        scanf("%d", &data[i]);
    }

    person = 3;
}

void Choose(int sum, int* temp){
    if(end){
        //printf("sum = %d, person = %d\n", sum, person);
        return;
    }

    if(number > 200){
        end = 1;
    }

    if(sum == separate){
        for(int i = 1; i <= cnt; i++){
            printf("temp[%d] = %d\n", i, temp[i]);
        }

        /*
        for(int i = 1; i <= cnt; i++){
            if(temp[i] != 0){
                printf("i = %d\n", i);
                cho[i] = temp[i];
            }
        }
        */

        end = 1;
    }

    for(int i = 1; i <= cnt; i++){
        if(cho[i] == 0){
            cho[i] = person;
            temp[i] = person;
            Choose(sum + data[i], temp);
            cho[i] = 0;
            temp[i] = 0;
            Choose(sum, temp);
        }
    }
}

void Sort(){
    for(int i = 1; i < cnt; i++){
        for(int j = i; j <= cnt; j++){
            if(data[j] < data[i]){
                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

void Process(){
    bool out = true, exist = false;
    while(out){
        if(person == 0){
            printf("out\n");
            break;
        }

        int sum = 0;

        for(int i = 1; i <= cnt; i++){
            if(cho[i] == 0){
                sum += data[i];
            }
        }

        separate = sum / person;
        printf("separate = %d\n", separate);

        /*
        int temp[cnt+1];
        for(int i = 0; i <= cnt; i++){
            temp[i] = 0;
        }
        */

        printf("person = %d\n", person);
        //Choose(0, temp);

        for(int i = 1; i <= cnt; i++){
            printf("choice[%d] = %d\n", i, cho[i]);
        }

        for(int i = 1; i <= cnt; i++){
            if(cho[i] == 0){
                out = true;
                break;
            }
        }

        for(int i = 1; i <= cnt; i++){
            if(cho[i] == person){
                exist = true;
                break;
            }
        }

        if(!exist){
            int big = 0, index = 0;

            for(int i = 1; i <= cnt; i++){
                if(big < data[i] && cho[i] == 0){
                    big = data[i];
                    index = i;
                }
            }
            cho[index] = person;
        }
        person--;
    }
    //Choose(0, 0, 2);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d %d %d\n", g1, g2, g3);
    fclose(stdout);
}

int main()
{
    //In();
    //Process();

    Input();
    ArrayPrn();
    std::sort(gift, gift+n, Desc);
    ArrayPrn();
    Solve(0, 0, 0, 0);
    Output();

    return 0;
}
