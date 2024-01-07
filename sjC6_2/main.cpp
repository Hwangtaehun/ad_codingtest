#include <iostream>
#include <fstream>
#define N 19

using namespace std;

class Omok{
private:
    int board[N][N];
    int result;
    int sx, sy;
    int ex, ey;
public:
    Omok();
    ~Omok();
    void process();
    void output();
    int getBoard(int x, int y);
};

Omok::Omok(){
    ifstream inf("input.txt");
    int i,j;

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            inf >> board[i][j];
        }
    }

    inf.close();
    result = 0;
}

Omok::~Omok(){}

int Omok::getBoard(int x, int y){
    if(x < 0){
        return 0;
    }

    if(y < 0){
        return 0;
    }

    if(x >= N){
        return 0;
    }

    if(y >= N){
        return 0;
    }

    return board[y][x];
}

void Omok::process(){
    const int direction[4][2] = {{1,0}, {0,1}, {1,1}, {1,-1}};
    int x, y, dir;
    int currentColor;
    for(dir = 0; dir < 4; dir++){
        for(y = 0; y < N; y++){
            for(x = 0; x < N; x++){
                int dir_x = direction[dir][0], dir_y = direction[dir][1];
                if((currentColor = getBoard(x, y)) && getBoard(x, y) != getBoard(x - dir_x, y - dir_y )){
                    int count = 0;
                    int xh = x, yh = y;
                    while(getBoard(xh, yh) == currentColor){
                        xh += dir_x;
                        yh += dir_y;
                        count++;
                    }

                    if(count == 5){
                        result = currentColor;
                        sx = x;
                        sy = y;
                        ex = xh;
                        ey = yh;
                        return;
                    }
                }
            }
        }
    }
}

void Omok::output(){
    ofstream ouf("output.txt");
    ouf << result << endl;
    if(result){
        ouf << sy + 1 << ' ' << sx + 1 << endl;
    }
    ouf.close();
}

int main()
{
    Omok b;
    b.process();
    b.output();
    return 0;
}
