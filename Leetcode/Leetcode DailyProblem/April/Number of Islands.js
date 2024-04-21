/**
 * @param {character[][]} grid
 * @return {number}
 */

function helper(grid, i, j, n, m) {
  if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] === "0") {
    return;
  }
  grid[i][j] = "0";
  let arrx = [-1, 0, 1, 0];
  let arry = [0, 1, 0, -1];
  for (let k = 0; k < 4; k++) {
    helper(grid, i + arrx[k], j + arry[k], n, m);
  }
}

var numIslands = function (grid) {
  let ans = 0;
  let n = grid.length;
  let m = grid[0].length;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (grid[i][j] === "1") {
        helper(grid, i, j, n, m);
        ans++;
      }
    }
  }
  return ans;
};

let grid = [
  ["1", "1", "0", "0", "0"],
  ["1", "1", "0", "0", "0"],
  ["0", "0", "1", "0", "0"],
  ["0", "0", "0", "1", "1"],
];
numIslands(grid);
