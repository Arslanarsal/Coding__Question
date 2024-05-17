/**
 * @param {number[][]} grid
 * @return {number}
 */
var matrixScore = function (grid) {
  let n = grid.length,
    m = grid[0].length;
  let ans = n * (1 << (m - 1));
  for (let j = 1; j < m; j++) {
    let cnt = 0;
    for (let i = 0; i < n; i++) {
      cnt += grid[i][0] === 0 ? grid[i][j] ^ 1 : grid[i][j];
    }
    if (cnt < n - cnt) {
      ans += (n - cnt) * (1 << (m - j - 1));
    }
    else {
      ans += (cnt) * (1 << (m - j - 1));
    }
  }
  return ans;
};
