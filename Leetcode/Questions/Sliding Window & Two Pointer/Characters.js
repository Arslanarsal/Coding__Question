/**
 * @param {string} s
 * @return {number}
 */
var numberOfSubstrings = function (s) {
    let n = s.length;
    let a = -1, b = -1, c = -1;
    let ans = 0;
    for (let i = 0; i < n; i++) {
        const element = array[i];
        if (s[i] === 'a') {
            a = i;
        }
        else if (s[i] === 'b') {
            b = i;
        }
        else {
            c = i;
        }
        if (a !== -1 && b !== -1 && c !== -1) {
            ans += 1 + Math.min(a, b, c);
        }
    }
    return ans;
};