class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int perimeter = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    // Check all 4 sides separately

                    // Up
                    if (i == 0 || grid[i - 1][j] == 0)
                        perimeter++;

                    // Down
                    if (i == m - 1 || grid[i + 1][j] == 0)
                        perimeter++;

                    // Left
                    if (j == 0 || grid[i][j - 1] == 0)
                        perimeter++;

                    // Right
                    if (j == n - 1 || grid[i][j + 1] == 0)
                        perimeter++;
                }
            }
        }

        return perimeter;
    }
};