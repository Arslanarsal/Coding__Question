/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */

function isvalid(board, row, col, k) {
  k = k.toString();
  for (let i = 0; i < 9; i++) {
    if (board[i][col] === k) {
      return false;
    }
    if (board[row][i] === k) {
      return false;
    }
    if (
      board[3 * Math.floor(row / 3) + Math.floor(i / 3)][
        3 * Math.floor(col / 3) + Math.floor(i % 3)
      ] === k
    ) {
      return false;
    }
  }
  return true;
}

function helper(board) {
  let n = board.length;
  let m = board[0].length;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (board[i][j] === ".") {
        for (let k = 1; k <= 9; k++) {
          if (isvalid(board, i, j, k)) {
            board[i][j] = k.toString();
            if (helper(board)) {
              return true;
            } else board[i][j] = ".";
          }
        }
        return false;
      }
    }
  }
  return true;
}

var solveSudoku = function (board) {
  helper(board);
};
