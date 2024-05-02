/**
 * @param {number[]} cardPoints
 * @param {number} k
 * @return {number}
 */
var maxScore = function (cardPoints, k) {
    let n = cardPoints.length;
    let left = 0;
    let right = 0;
    let ans = 0;
    for (let i = 0; i < k; i++) {
        left += cardPoints[i];
    }
    ans = left;
    if (n === k) {
        return ans;
    }
    for (let i = 0; i < k; i++) {
        left -= cardPoints[ k - i -1];
        right += cardPoints[n - i - 1];
        ans = Math.max(ans, left + right);


    }
    return ans;
};