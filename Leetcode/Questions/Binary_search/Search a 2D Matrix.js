/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function (matrix, target) {
    let n = matrix.length, m = matrix[0].length;
    let low = 0, high = n * m - 1;
    while (low <= high) {
        let mid = Math.floor((low + high) / 2);
        let row = Math.floor(mid / m), col = Math.floor(mid % m);
        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] <= target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
};

let arr = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]];
console.log(searchMatrix(arr, 13));

