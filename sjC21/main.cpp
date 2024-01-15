#include <cstdio>

int data[16], separate;
int cnt, person, end;
int cho[16] = {0,};

void In(){
    freopen("input.txt", "r", stdin);

    scanf("%d", &cnt);
    for(int i = 1; i <= cnt; i++){
        scanf("%d", &data[i]);
    }

    person = 3;
}

void Choose(int num, int sum, int temp[]){
    if(end || num == cnt){
        //printf("sum = %d, person = %d\n", sum, person);
        return;
    }

    if(sum == separate){
        for(int i = 1; i <= cnt; i++){
            if(temp[i] != 0){
                cho[i] = temp[i];
            }
        }
        end = 1;
    }


    /*
    for(int i = 1; i <= cnt; i++){
        if(cho[i] == 0){
            cho[i] = person;
            temp[i] = person;
            Choose(num, sum + data[i], temp);
            cho[i] = 0;
            temp[i] = person;
            Choose(num, sum, temp);
        }
    }
    */
    if(cho[num+1] == 0){
        temp[num+1] = person;
        Choose(num+1, sum + data[num+1], temp);
        temp[num+1] = 0;
        Choose(num+1, sum, temp);
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

        int temp[cnt+1];
        for(int i = 0; i <= cnt; i++){
            temp[i] = 0;
        }

        printf("person = %d\n", person);
        Choose(0, 0, temp);

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

int main()
{
    In();
    Process();

    cho[6] = 3;
    separate = 12;

    int temp[cnt+1];
    for(int i = 0; i <= cnt; i++){
        temp[i] = 0;
    }

    Choose(0, 1, temp);
    for(int i = 1; i <= cnt; i++){
        printf("cho[%d] = %d\n", i, cho[i]);
    }
    return 0;
}
