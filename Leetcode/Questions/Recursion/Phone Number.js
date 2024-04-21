/**
 * @param {string} digits
 * @return {string[]}
 */

function helper(digits, idx, ans, temp, mp) {
  if (idx >= digits.length) {
    ans.push(...temp);
    return;
  }
  let ch = digits[idx];
  let str = mp[ch.charCodeAt() - "0".charCodeAt()];

  for (let i = 0; i < str.length; i++) {
    temp += str[i];
    helper(digits, idx + 1, ans, temp, mp);
    temp.pop();
  }
}

var letterCombinations = function (digits) {
    if (!digits.length) {
        return [];
    }
  let mp = new Map();
  mp[2] = "abc";
  mp[3] = "def";
  mp[4] = "ghi";
  mp[5] = "jkl";
  mp[6] = "mno";
  mp[7] = "pqrs";
  mp[8] = "tuv";
  mp[9] = "wxyz";
  let ans = [];
  helper(digits, 0, ans, "", mp);
  let an = "";

  return ans;
};
