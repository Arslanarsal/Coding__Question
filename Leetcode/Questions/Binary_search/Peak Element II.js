/**
 * @param {number[][]} mat
 * @return {number[]}
 */


function getmaxele(mat, mid) {
    let n = mat.length;
    let ind = 0;
    let maxele = Number.MIN_SAFE_INTEGER;
    for (let i = 0; i < n; i++) {
        if (mat[i][mid] > maxele) {
            maxele = mat[i][mid];
            ind = i;
        }
    }
    return ind;
}



var findPeakGrid = function (mat) {
    let n = mat.length ;
    let m = mat[0].length;
    let i = 0, j = n-1;
    while (i <= j) {
        let mid = Math.floor((i + j) / 2);

        let maxind = getmaxele(mat, mid);

        let left = mid - 1 >= 0 ? mat[maxind][mid - 1] : -1;
        let right = mid + 1 < m ? mat[maxind][mid + 1] : -1;

        if (left < mat[maxind][mid] && right < mat[maxind][mid]) {
            return [maxind, mid];
        }
        else if (left > mat[maxind][mid]) {
            j = mid - 1;
        } else {
            i = mid + 1;
        }
    }

    return [-1, -1];
};