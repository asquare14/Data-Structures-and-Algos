#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/number-of-islands/
int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void DFS(vector<vector<int>>& board, int i, int j, int m, int n)
{
        if (i < 0 || i == m || j < 0 || j == n || board[i][j] == 0) {
            return;
        }
        for (auto d : dirs) {
          int x = i + d[0], y = j + d[1];
          board[i][j] = 0;
          DFS(board, x, y, m, n);
      } 
}
int connectedComponents(vector<vector<int>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();
        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
          for (int c = 0; c < nc; ++c) {
            if (grid[r][c] == 1) {
                num_islands++;
                DFS(grid, r, c,nr,nc);
            }
          }
        }

        return num_islands;
}
int main()
{
   vector<vector<int>> grid ={{1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1},
                   {1, 0, 0, 1, 1},
                   {0, 0, 0, 0, 0},
                   {1, 0, 1, 0, 1}};
    cout<<connectedComponents(grid);
}