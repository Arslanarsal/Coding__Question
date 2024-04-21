/**
 * @param {number} k
 * @param {number} n
 * @return {number[][]}
 */

function helper(ans, temp, num, i, n, k) {
  if (num === n && temp.length == k) {
    ans.push([...temp]);
    return;
  }

  for (let ind = i; ind < 10, ind <= n; ind++) {
    temp.push(ind);
    helper(ans, temp, num + ind, ind + 1, n, k);
    temp.pop();
  }
}

var combinationSum3 = function (k, n) {
  let ans = [];
  helper(ans, [], 0, 1, n, k);
  return ans;
};

let ans = combinationSum3(3, 9);
for (let i = 0; i < ans.length; i++) {
  console.log(ans[i]);
}
