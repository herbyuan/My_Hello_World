/*
*程序名：
*作者：何卓远
*编制时间：2018-12-
*功能：
*/
#include <iostream>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int N, M;
char a[110][110];
int bx, by, ix, iy;
int v[110][110];
struct Node
{
    int x;
    int y;
    int s;
    Node(int _x, int _y, int _s)
    {
        x = _x;
        y = _y;
        s = _s;
    }
};
int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        queue<Node> q;        
        memset(a, 0, sizeof(a));
        memset(v, 0, sizeof(v));
        cin >> N >> M;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                cin >> a[i][j];
                if(a[i][j] == 'B')
                {
                    bx = i;
                    by = j;
                    q.push(Node(i, j, 0));
                    v[i][j] = 1;
                }
                if(a[i][j] == 'I')
                {
                    ix = i;
                    iy = j;
                }
            }
        }
        int flag = 0;
        while(q.size())
        {
            auto p = q.front();
            q.pop();
            if (a[p.x][p.y] == 'I')
            {
            	printf("Case #%d: %d\n", t + 1, p.s);
                flag = 1;
                break;
            }
            int px = p.x;
            int py = p.y;

            if(a[px][py] >= 'a' && a[px][py] <= 'z')
            {
                for (int i = 0; i < N; ++i)
                {
                    for (int j = 0; j < M; ++j)
                    {
                        if(a[i][j] == a[px][py] && i != px && j != py && v[i][j] == 0)
                        {
                            v[i][j] = 1;
                            q.push(Node(i, j, p.s + 1));
                        }
                    }
                }
            }
            for (int i = 0; i < 4; ++i)
            {
                int tx = px + dx[i];
                int ty = py + dy[i];
                if(tx >= 0 && ty >= 0 && tx < N && ty < M && a[tx][ty] != '#' && v[tx][ty] == 0)
                {
                    v[tx][ty] = 1;
                    q.push(Node(tx, ty, p.s + 1));
                }
            }
        }
        if(flag == 0)
        {
        	printf("Case #%d: -1\n", t + 1);
        }
    }
    return 0;
}