// ! Time: O(n + n) (BFS) and Space for queue -O(n) and space for dirx,diry
// code snippet
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void pushNeighbours(queue<pair<int, pair<int, int>>> &q, int x, int y, vector<vector<int>> &grid, int n, int pathCount)
    {

        int dirx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int diry[] = {-1, -1, -1, 0, 0, 1, 1, 1};

        for (int i = 0; i < 8; i++)
        {

            if (x + dirx[i] < 0 || x + dirx[i] >= n || y + diry[i] < 0 || y + diry[i] >= n ||
                grid[x + dirx[i]][y + diry[i]] == 1)
                continue; // Ignore neighbour case

            q.push({pathCount + 1, {x + dirx[i], y + diry[i]}});
            grid[x + dirx[i]][y + diry[i]] = 1;
        }
    }
    void bfs(vector<vector<int>> &grid, int n, int &path, queue<pair<int, pair<int, int>>> q)
    {

        q.push({1, {0, 0}}); // Path count = 1
        grid[0][0] = 1;

        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();

            int pathCount = temp.first;
            pair<int, int> coor = temp.second;

            int x = coor.first;
            int y = coor.second;
            if (x == n - 1 && y == n - 1)
            {
                path = pathCount;
                // break;
            }

            pushNeighbours(q, x, y, grid, n, pathCount);
        }
    }
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();

        if (grid[0][0] || grid[n - 1][n - 1])
            return -1;

        int path = -1;

        queue<pair<int, pair<int, int>>> q;

        bfs(grid, n, path, q);

        return path;
    }
};