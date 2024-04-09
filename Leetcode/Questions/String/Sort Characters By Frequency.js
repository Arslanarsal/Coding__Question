/**
 * @param {string} s
 * @return {string}
 */
var frequencySort = function (s) {
  let ans = "";
  let n = s.length;
  let mp = new Map();

  for (let i = 0; i < n; i++) {
    if (mp.has(s[i])) {
      mp.set(s[i], mp.get(s[i]) + 1);
    } else {
      mp.set(s[i], 1);
    }
  }

  let arr =  Array.from(mp.entries());

  arr.sort((a, b) => b[1] - a[1]);

  for (const [char, count] of arr) {
    ans = ans + char.repeat(count);
  }

  return ans;
};
