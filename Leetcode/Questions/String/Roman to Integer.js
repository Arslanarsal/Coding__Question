/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function (s) {
  let mp = new Map();
  mp.set("I", 1);
  mp.set("V", 5);
  mp.set("X", 10);
  mp.set("L", 50);
  mp.set("C", 100);
  mp.set("D", 500);
  mp.set("M", 1000);
  let n = s.length;
  let ans = 0;

  for (let i = 0; i < n; i++) {
    if (mp.get(s[i]) < mp.get(s[i + 1])) {
      ans -= mp.get(s[i]);
    } else {
      ans += mp.get(s[i]);
    }
  }
  return ans;
};

let s = "MCMXCIV";
console.log(romanToInt(s));
