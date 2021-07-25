#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;


/**
 * Made by Illedan.
 **/

#define WIDTH 30
#define HEIGHT 20

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
//
//  0->E 1->W 2->S 3->N
//
char m[HEIGHT][WIDTH];
int visited[HEIGHT][WIDTH];  // Mark whether to walk
bool f;             // Used to determine whether a snake is found.

struct node {
    int x;          // Abscissa
    int y;          // Y-axis
    string s;       // Path record
};

string BFS(int x, int y) {
    visited[y][x] = 1;
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
        if (m[b.y][b.x] == 'F')
            // You can also save the coordinates of 'E' during input and compare them.
        {
            f = 1;  //mark
            return b.s; //End of function
        }
        for (int i = 0; i < 4; i++) {
            c = b;
            c.x += dx[i];
            c.y += dy[i];
            if (visited[c.y][c.x] == 0 && c.x >= 0 && c.x < WIDTH && c.y >= 0 && c.y < HEIGHT && m[c.y][c.x] != 'S') {
                visited[c.y][c.x] = 1;
                //  0->E 1->W 2->S 3->N
                if (i == 0) c.s += 'E';
                else if (i == 1) c.s += 'W';
                else if (i == 2) c.s += 'S';
                else if (i == 3) c.s += 'N';
                q.push(c);
            }
        }
    }
}


int main() {
    int width;
    int height;
    cin >> width >> height;
    cin.ignore();
    //cerr << width << " " << height <<endl;

    // game loop
    while (1) {
        int seed;
        int score;
        int snakeSize;
        int currentFoundCount;
        string path;
        int sx, sy; //The abscissa and ordinate of 'S'

        memset(visited, 0, sizeof(visited));
        memset(m, '.', sizeof(m) + 1);
        path.clear();
        
        cin >> seed >> score >> snakeSize >> currentFoundCount;
        cin.ignore();
        //cerr << seed << " " << score << " " << snakeSize << " " << currentFoundCount <<endl;

        for (int i = 0; i < snakeSize; i++) {
            int snakeX;
            int snakeY;
            cin >> snakeX >> snakeY;
            //cerr << snakeX << " " << snakeY <<endl;
            m[snakeY][snakeX] = 'S';
            if (i == 0) {
                sx = snakeX;
                sy = snakeY;
            }
            cin.ignore();
        }
        for (int i = 0; i < currentFoundCount; i++) {
            int x;
            int y;
            cin >> x >> y;
            //cerr << x << " " << y << endl;
            m[y][x] = 'F';
            cin.ignore();
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        // for (int i = 0; i < HEIGHT; i++) {
        //     for (int j = 0; j <= WIDTH; j++)
        //         cerr << m[i][j] << " ";
        //     cerr << endl;
        // }

        path = BFS(sx, sy);    //  Guangsou
        if (f == 0)     //  Can't eat food
            cout << "Can't eat it!" << endl;

        // cerr << path << endl;
        cout << path[0] << endl;
        // exit(0);
    }
}
