#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int kind;
string data[20][2], str, result;
char data_s[20];

void In(){
    freopen("input.txt", "r", stdin);
    cin >> kind;
    for(int i = 0; i < kind; i++){
        cin >> data[i][0] >> data[i][1];
    }
    cin >> str;
    fclose(stdin);
}

int Word(int cnt){
    for(int i = 0; i < kind; i++){
        if(data_s[i] ==  str.at(cnt)){
            string word, huff = data[i][1];
            int length = huff.size();

            for(int j = cnt; j < cnt + length; j++){
                string temp = string(1, str.at(j));
                word.append(temp);
            }

            if(huff == word){
                result.append(data[i][0]);
                return  cnt + length;
            }
        }
    }

    return 0;
}

void Incoding(){
    int cnt = 0, length = str.length();

    for(int i = 0; i < kind; i++){
        data_s[i] = data[i][1].at(0);
    }

    while(cnt != length){
        cnt = Word(cnt);

        if(cnt == 0){
            cout << "오류 발생했습니다.\n";
            return;
        }
    }
}

void Out(){
    freopen("output.txt", "w", stdout);
    cout << result;
    fclose(stdout);
}

int main()
{
    In();
    Incoding();
    Out();
    return 0;
}
