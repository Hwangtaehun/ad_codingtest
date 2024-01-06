#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int vertex, edge, cost;
bool visited[11];
std::vector< pair <int, int> > v[60];//data ตฅภฬลอ

void Input(){
    int a, b, w;

    freopen("input.txt", "r", stdin);

    scanf("%d %d", &vertex, &edge);
    for(int i = 0; i < edge; i++){
        scanf("%d %d %d", &a, &b, &w);
        v[a].push_back(make_pair(b, w));
        v[b].push_back(make_pair(a, w));
    }
}


void Solve(){
    std:queue <int> q;
    int currentNode;
    int node = 1;

    q.push(node);
    visited[node] = true;

    while(currentNode != 7){
        currentNode = q.front();
        q.pop();
        printf("%d ->\n", currentNode);
        int index = v[currentNode].size();
        int temp[index][2];


        for(int i = 0; i < index; i++){
            temp[i][0] = v[currentNode][i].first;
            temp[i][1] = v[currentNode][i].second;
        }

        for(int i = 0; i < index-1; i++){
            for(int j = i+1; j < index; j++){
                int value, node;
                if(temp[j][1] < temp[i][1] ){
                    node = temp[i][0];
                    value = temp[i][1];
                    temp[i][0] = temp[j][0];
                    temp[i][1] = temp[j][1];
                    temp[j][0] = node;
                    temp[j][1] = value;
                }
            }
        }

        for(int i = 0; i < index; i++){
            printf("temp[%d][0] = %d, temp[%d][1] = %d\n", i, temp[i][0], i, temp[i][1]);
        }

        for(int i = 0; i < index; i++){
            printf("temp[%d][0] =  %d\n", i, temp[i][0]);
            if(!visited[temp[i][0]]){
                visited[temp[i][0]] = true;
                q.push(temp[i][0]);
                cost += temp[i][1];
                break;
            }
        }
    }

}

void Output(){
    printf("vertex =  %d, edge = %d\n", vertex, edge);
    for(int i = 1; i <= vertex; i++){
        printf("v[i].size() =  %d\t", v[i].size());
        printf("node %d : ", i);
        for(int j = 0; j < v[i].size(); j++){
            printf("%5d%5d", v[i][j].first, v[i][j].second);
        }
        printf("\n");
    }
}

int main()
{
    Input();
    Solve();

    return 0;
}
