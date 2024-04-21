class Solution {
  helper(n, m, i, j, temp, ans) {
    if (i === n - 1 && j === n - 1) {
      ans.push([temp]);
      return;
    }
    let row = [-1, 0, 1, 0];
    let col = [0, 1, 0, -1];

    for (let k = 0; k < 4; k++) {
      let newi = i + row[k];
      let newj = j + col[k];
      if (newi >= 0 && newi < n && newj >= 0 && newj < n && m[newi][newj]) {
        if (k == 0) {
          temp += "U";
        } else if (k == 1) {
          temp += "R";
        } else if (k == 2) {
          temp += "D";
        } else {
          temp += "L";
        }
        m[i][j] = 0;
        this.helper(n, m, newi, newj, temp, ans);
        m[i][j] = 1;
        temp = temp.slice(0, -1);
      }
    }
  }

  findPath(m, n) {
    let ans = [];
    if (m[0][0] === 0) {
      return ans;
    }
    this.helper(n, m, 0, 0, "", ans);
    return ans;
  }
}

const solution = new Solution();
const maze = [
  [1, 0, 0, 0],
  [1, 1, 0, 1],
  [1, 1, 0, 0],
  [0, 1, 1, 1],
];
const paths = solution.findPath(maze, maze.length);
console.log(paths);
