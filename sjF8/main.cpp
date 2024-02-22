#include<map>
#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int kind;
string data[20][2], stance, result;
char data_s[20];

//solve
map <string, char> mp;
int k, i;
char ch;
string str, a;

void Input(){
    freopen("input.txt", "r", stdin);
    cin >> k;
    for(i = 0; i < k; i++){
        cin >> ch >> str;
        mp[str] = ch;
    }
    cin >> str;
    fclose(stdin);
}

void In(){
    freopen("input.txt", "r", stdin);
    cin >> kind;
    for(int i = 0; i < kind; i++){
        cin >> data[i][0] >> data[i][1];
    }
    cin >> stance;
    fclose(stdin);
}

int Word(int cnt){
    for(int i = 0; i < kind; i++){
        if(data_s[i] ==  stance.at(cnt)){
            string word, huff = data[i][1];
            int length = huff.size();

            for(int j = cnt; j < cnt + length; j++){
                string temp = string(1, stance.at(j));
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
    int cnt = 0, length = stance.length();

    for(int i = 0; i < kind; i++){
        data_s[i] = data[i][1].at(0);
    }

    while(cnt != length){
        cnt = Word(cnt);

        if(cnt == 0){
            cout << "      ߻  ߽  ϴ .\n";
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
    Input();
    for(i = 0; i < str.length(); i++){
        a += str[i];

        if(mp[a]){
            cout << mp[a];
            a.clear();
        }
    }
    return 0;
}
