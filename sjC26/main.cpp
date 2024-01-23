#include <cstdio>

char angle[20], devil[20], word[10];
int word_size, bridge_size, endSw, kind = 0;

//solve
char scroll[11], bridge[2][21];
int result = 0;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%s %s %s", scroll, bridge[0], bridge[1]);
    fclose(stdin);
}

int Solve(int row, int n, int rp){
    int i, c = 0, next;

    if(scroll[rp] == '\0'){
        return 1;
    }

    for(i = n; bridge[row][i] != '\0'; i++){
        if(bridge[row][i] == scroll[rp]){
            printf("%d,%c ", i, scroll[rp]);
            next = (row == 0) ? 1 : 0;
            c += Solve(next, i + 1, rp + 1);
            if(c > 0){
                printf("aaa\n");
            }
        }
    }
    return c;
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", result);
    fclose(stdout);
}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%s", word);
    scanf("%s", devil);
    scanf("%s", angle);
    fclose(stdin);

    int i = 0;
    for(i = 0; i < 20;  i++){
        if(angle[i] == '\0'){
            break;
        }
    }
    bridge_size = i;

    for(i = 0; i < 10;  i++){
        if(word[i] == '\0'){
            break;
        }
    }
    word_size = i;
}

void Route(int index, int word_index, int bridge){
    int character[bridge_size], char_index = 0;

    //printf("kind = %d, bridge = %d\n", kind, bridge);
    //printf("word_index = %d\n", word_index);
    //printf("index = %d, word_size= %d\n", index, word_size);

    if(endSw){
        return;
    }

    if(word_index == word_size){
        //printf("if문 실행\n");
        kind++;
        return;
    }

    if(index > bridge_size){
        endSw = 1;
        return;
    }

    //angel
    if(bridge < 0){
        for(int i = index; i < bridge_size; i++){
            //printf("angle[%d] = %c\n", i, angle[i]);
            if(word[word_index] == angle[i]){
                //printf("실행\n");
                character[char_index] = i;
                char_index++;
            }
        }
    }
    else{
        for(int i = index; i < bridge_size; i++){
            //printf("devil[%d] = %c\n", i, devil[i]);
            if(word[word_index] == devil[i]){
                //printf("실행\n");
                character[char_index] = i;
                char_index++;
            }
        }
    }

    //printf("char_index = %d\n", char_index);

    if(char_index != 0){
        for(int i = 0; i < char_index; i++){
            Route(character[i]+1, word_index+1, -bridge);
        }
    }else{
        endSw = 1;
    }
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", kind);
    fclose(stdout);
}

int main()
{
    //In();
    //Route(0,0,1);
    //endSw = 0;
    //Route(0,0,-1);
    //Out();
    Input();
    result += Solve(0,0,0);
    result += Solve(1,0,0);
    Output();
    return 0;
}
