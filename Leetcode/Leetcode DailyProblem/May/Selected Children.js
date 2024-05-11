/**
 * @param {number[]} happiness
 * @param {number} k
 * @return {number}
 */
var maximumHappinessSum = function (happiness, k) {
    let ans = 0;
    let m = k;
    let n = happiness.length;
    happiness.sort((a, b) => b - a);
    for (let i = 0; i < k; i++) {
        let minus = k - m;
        if (happiness[i] < minus) {
            break;
        }
        ans += (happiness[i] - minus);
        m--;
    }
    return ans;
};