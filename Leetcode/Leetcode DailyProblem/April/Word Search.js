/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */


function check(i, j, k, board, word, previs, n, m) {
    if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] !== word[k] || previs[i][j]) {
        return false;
    }
    if (k === word.length - 1) {
        return true;
    }
    previs[i][j] = 1;

    let arri = [-1, 0, 1, 0];
    let arrj = [0, 1, 0, -1];

    for (let x = 0; x < 4; x++) {
        if (check(i + arri[x], j + arrj[x], k + 1, board, word, previs, n, m)) {
            return true;
        }
    }

    arri = [-1, -1, 1, 1];
    arrj = [-1, 1, 1, -1];

    for (let x = 0; x < 4; x++) {
        if (check(i + arri[x], j + arrj[x], k + 1, board, word, previs, n, m)) {
            return true;
        }
    }
    previs[i][j] = 0;
    return false;

}


var exist = function (board, word) {
    let n = board.length;
    let m = board[0].length;
    let previs = new Array(n).fill().map(() => new Array(m).fill(0));
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (board[i][j] == word[0]) {
                let flage = check(i, j, 0, board, word, previs, n, m);
                if (flage) {
                    return true;
                }
            }
        }
    }
    return false;
};