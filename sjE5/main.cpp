#include <cstdio>

int s, e, d;

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &s, &e);
    fclose(stdin);
}

int Node(int num){
    if(num == 1){
        return 0;
    }

    return 1 + Node(num/2);
}

void Find(){
    int m_s = s, m_e = e ,level_s = Node(s), level_e = Node(e), m;

    while(level_s != level_e){
        if(level_s > level_e){
            m_s /= 2;
            level_s--;
        }
        else{
            m_e /= 2;
            level_e--;
        }
    }

    while(m_s != m_e){
        m_s /= 2;
        m_e /= 2;
    }


    m = m_s;
    m_e = e, m_s = s;

    while(m != m_e){
        m_e /= 2;
        d++;
    }

    while(m != m_s){
        m_s /= 2;
        d++;
    }
}


void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", d);
    fclose(stdout);
}

int main()
{
    In();
    Find();
    Out();
    return 0;
}
