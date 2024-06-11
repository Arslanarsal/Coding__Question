/**
 * @param {string} s
 * @return {number}
 */
var minAddToMakeValid = function (s) {
    let stack = [];
    let ans = 0;
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(') {
            stack.push('(');
        }
        else if (s[i] === ')' && stack.length) {
            stack.pop();
        } else {
            ans++;
        }
    }
    while (stack.length) {
        ans++;
        stack.pop();
    }
    return ans;
};