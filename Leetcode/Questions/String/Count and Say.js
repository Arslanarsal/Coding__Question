/**
 * @param {number} n
 * @return {string}
 */
function solve(s) {
    let n = s.length;
    let i = 0;
    let ans = "";
    while (i < n) {
        let j = 1;
        while (i < n - 1 && s[i] == s[i + 1]) {
            i++;
            j++;
        }
        ans += j.toString() + s[i];
        i++;
    }
    return ans;
}

var countAndSay = function (n) {
    if (n == 1) {
        return "1";
    }
    let ret = countAndSay(n - 1);
    return solve(ret);
};

console.log(countAndSay(4));