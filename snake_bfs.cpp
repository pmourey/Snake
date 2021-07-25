#include<bits/stdc++.h>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
//
//  0->S 1->N 2->E 3->W
//
char m[110][110];
int vis[110][110];  // Mark whether to walk
bool f;             // Used to determine whether a snake is found.
int R, C;
struct node {
    int x;          // Abscissa
    int y;          // Y-axis
    string s;       // Path record
};

void BFS(int x, int y) {
    vis[x][y] = 1;
    node a;         // initial
    a.x = x;
    a.y = y;
    a.s.clear();
    node b, c;
    queue<node> q;
    q.push(a);
    while (!q.empty())  //BFS core code
    {
        b = q.front();
        q.pop();
        if (m[b.x][b.y] == 'E')
            // You can also save the coordinates of 'E' during input and compare them.
        {
            f = 1;  //mark
            cout << b.s << endl;
            return; //End of function
        }
        for (int i = 0; i < 4; i++) {
            c = b;
            c.x += dx[i];
            c.y += dy[i];
            if (vis[c.x][c.y] == 0 && c.x > 0 && c.x <= R && c.y > 0 && c.y <= R && m[c.x][c.y] != '#') {
                vis[c.x][c.y] = 1;
                if (i == 0) c.s += 'S';
                else if (i == 1) c.s += 'N';
                else if (i == 2) c.s += 'E';
                else if (i == 3) c.s += 'W';
                q.push(c);
            }
        }
    }
}

int main() {
    while (cin >> R >> C) {
        int sx, sy;//The abscissa and ordinate of'S'
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++) {
                cin >> m[i][j];
                if (m[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
            }
        f = 0;
        BFS(sx, sy);    //  Guangsou
        if (f == 0)     //  Can't eat food
            cout << "Can't eat it!" << endl;
    }
    return 0;
}

