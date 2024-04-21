/**
 * @param {number} n
 * @return {string[][]}
 */

function issafe(row, col, temp , n) {
  let duprow = row;
  let dupcol = col;
  while (dupcol >= 0 && duprow >= 0) {
    if (temp[duprow][dupcol] === "Q") {
      return false;
    }
    dupcol--;
    duprow--;
  }

  duprow = row;
  dupcol = col;
  while (dupcol < n && duprow >= 0) {
    if (temp[duprow][dupcol] === "Q") {
      return false;
    }
    dupcol++;
    duprow--;
  }

  duprow = row;
  dupcol = col;
  while (duprow >= 0) {
    if (temp[duprow][dupcol] === "Q") {
      return false;
    }
    duprow--;
  }
  return true;
}

function helper(idx, preidx, temp, ans, n) {
  if (idx >= n) {
    ans.push([...temp]);
    return;
  }

  for (let i = 0; i < n; i++) {
    if (issafe(idx, i, temp , n)) {
      temp[idx] = temp[idx].substring(0, i) + "Q" + temp[idx].substring(i + 1);
      helper(idx + 1, i, temp, ans, n);

      temp[idx] = temp[idx].substring(0, i) + "." + temp[idx].substring(i + 1);
    }
  }
}

var solveNQueens = function (n) {
  let temp = new Array(n).fill(".".repeat(n));
  let ans = [];
  helper(0, -1, temp, ans, n);
  return ans;
};
let ans = solveNQueens(4);
for (let i = 0; i < ans.length; i++) {
  console.log(ans[i]);
}
2;
