#pragma once
#include<queue>
#include<cstdio>
#include<string>
#include<string>
#include<iostream>
#include<cstdio>
#define check(x,y) (x>=0&&x<n&&y>=0&&y<m)
using namespace std;
const int MaxSize = 1010;
int n, m, si, sj, ei, ej;
int map[MaxSize][MaxSize], prex[MaxSize][MaxSize], prey[MaxSize][MaxSize];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool vis[MaxSize][MaxSize];
struct node {
	int x, y;
	node() {}
	node(int x_, int y_) {
		x = x_; y = y_;
	}
};
void printmap()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 2)
				printf("%c", '+');
			else
				printf("%d", map[i][j]);
		}
		puts("");
	}
}
void makepath(int x, int y)
{
	if (x == -1 && y == -1) return;
	map[x][y] = 2;
	makepath(prex[x][y], prey[x][y]);
}
int BFS(int si, int sj, int ei, int ej)
{
	memset(vis, 0, sizeof(vis));
	memset(prex, -1, sizeof(prex));
	memset(prey, -1, sizeof(prey));
	queue<node> Q;
	Q.push(node(si, sj));
	vis[si][sj] = 1;
	bool ok = 0;
	while (!Q.empty()) {
		node p = Q.front();
		Q.pop();
		if (p.x == ei&&p.y == ej) {
			ok = 1;
			makepath(ei, ej);
			return 1;
		}
		for (int k = 0; k < 4; k++) {
			int xx = p.x + dx[k], yy = p.y + dy[k];
			if (check(xx, yy) && !vis[xx][yy] && map[xx][yy] == 0) {
				Q.push(node(xx, yy));
				vis[xx][yy] = 1;
				prex[xx][yy] = p.x;
				prey[xx][yy] = p.y;
			}
		}
	}
	if (!ok) {
		puts("No Path Found.\n");
	}
	return ok;
}
void FindingPath()
{
	n = 0, m = -1;
	FILE *fs;
	fopen_s(&fs, "map.in", "r");
	string str;
	char strch[1024];
	while (fgets(strch, 1024, fs) != NULL) {
		str = string(strch);
		//		cout << "str:" << str << endl;
		if (m == -1) {
			if (str[str.length() - 1] == '\n')
				m = str.length() - 1;
			else
				m = str.length();

		}
		for (int j = 0; j < m; j++) {
			map[n][j] = (str[j] == '1');
		}
		n++;
	}
	puts("Map loaded as:");
	printmap();
	puts("Please input the Start position:");
	cin >> si >> sj;
	puts("Please input the End position:");
	cin >> ei >> ej;
	bool found = BFS(si, sj, ei, ej);
	if (found)
		printmap();
}