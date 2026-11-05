class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        def dfs(r, c):
            if r == len(grid) - 1 and c == len(grid[0]) - 1:
                return grid[r][c]
            if r == len(grid) or c == len(grid[0]):
                return float('inf')
            return grid[r][c] + min(dfs(r + 1, c), dfs(r, c + 1))

        return dfs(0, 0)