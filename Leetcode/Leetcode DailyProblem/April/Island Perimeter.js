

var islandPerimeter = function (grid) {
  let n = grid.length;
  let m = grid[0].length;
  let ans = 0;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (grid[i][j]) {
        if (i == 0 || !grid[i - 1][j]) {
          ans += 1;
        }
        if (j == m - 1 || !grid[i][j + 1]) {
          ans += 1;
        }

        if (i == n - 1 || !grid[i + 1][j]) {
          ans += 1;
        }
        if (j == 0 || !grid[i][j - 1]) {
          ans += 1;
        }
      }
    }
  }
  return ans;
};
