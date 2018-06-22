#include <iostream>
#define check(x, y) (x > 0 && x <= n && y > 0 && y <= n)

int ans[1005][1005] = {0}, temp[100005][2], tem, n, m;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool vi[1005][1005] = {true};
char ma[1005][1005];

void dfs(int i, int j);

int main(int argc, const char * argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			std::cin >> ma[i][j];
			vi[i][j] = false;
		}
	
	for (int i = 1; i <= n; i++)
    	for (int j = 1; j <= n; j++)
			if (!vi[i][j]) {
        		vi[i][j] = true;
        		tem = 0;
        		dfs(i, j);
        		for(int l = 1; l <= tem; l++)
					ans[temp[l][0]][temp[l][1]] = tem;
    		}
	int x, y;
	for (int i = 0; i < m; i++) {
		std::cin >> x >> y;
		std::cout << ans[x][y] << std::endl;
	}
	
	return 0;
}

void dfs(int i, int j) {
	tem++;
    temp[tem][0] = i, temp[tem][1] = j;
    for (int p = 0; p < 4; p++) {
        if (check((i + dx[p]), (j + dy[p])) && !vi[(i + dx[p])][(j + dy[p])] && ma[i][j] != ma[(i + dx[p])][(j + dy[p])]) {
            vi[(i + dx[p])][(j + dy[p])] = true;
            dfs((i + dx[p]), (j + dy[p]));
        }
    }
}
