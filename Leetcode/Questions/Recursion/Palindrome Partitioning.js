/**
 * @param {string} s
 * @return {string[][]}
 */
function ispalindr(s, start, end) {
  while (start <= end) {
    if (s[start++] != s[end--]) {
      return false;
    }
  }
  return true;
}

function helper(idx, s, ans, temp) {
  if (idx >= s.length) {
    ans.push([...temp]);
    return;
  }

  for (let i = idx; i < s.length; i++) {
    if (ispalindr(s, idx, i)) {
      temp.push(s.substring(idx, i + 1));
      helper(i + 1, s, ans, temp);
      temp.pop();
    }
  }
}
var partition = function (s) {
  let ans = [];
  helper(0, s, ans, []);
  return ans;
};
