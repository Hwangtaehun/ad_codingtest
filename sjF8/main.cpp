#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int kind;
string data[20][2], str;

void In(){
    freopen("input.txt", "r", stdin);
    cin >> kind;
    for(int i = 0; i < kind; i++){
        cin >> data[i][0] >> data[i][1];
    }
    cin >> str;
    fclose(stdin);
}

void Incoding(){
    int cnt = 0;
    int max_lenght = (kind) / 2 + 1;

    for(int i = 0; i < max_lenght; i++){
        if(str.at(i) == '0'){
            break;
        }
    }
}

int main()
{
    In();

    return 0;
}
