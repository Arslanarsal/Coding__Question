/**
 * @param {string} num
 * @param {number} target
 * @return {string[]}
 */

function helper(num, target, ans, str, i, temp, prev) {
  if (i === str.length) {
    if (num === target) {
      ans.push(temp);
    }
    return;
  }

  for (let j = i; j < str.length; j++) {
    if (j !== i && str[i] === "0") break; // Avoid leading zeros

    const cur = parseInt(str.substring(i, j + 1));

    if (i === 0) {
      helper(cur, target, ans, str, j + 1, temp + cur, cur);
    } else {
      helper(num + cur, target, ans, str, j + 1, temp + "+" + cur, cur);
      helper(num - cur, target, ans, str, j + 1, temp + "-" + cur, -cur);
      helper(
        num - prev + prev * cur,
        target,
        ans,
        str,
        j + 1,
        temp + "*" + cur,
        prev * cur
      );
    }
  }
}

var addOperators = function (num, target) {
  let ans = [];
  helper(0, target, ans, num, 0, "", 0);
  return ans;
};

let ans = addOperators("123", 6);
console.log(ans);
