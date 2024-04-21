/**
 * @param {string} s
 * @param {string[]} wordDict
 * @return {boolean}
 */

function helper(s, wordDict, dp, idx) {
  if (s.length === idx) {
    return true;
  }
  if (dp[idx] != -1) {
    return dp[idx];
  }
  //   console.log(s);
  for (let i = idx; i <= s.length; i++) {
    for (let j = 0; j < wordDict.length; j++) {
      if (s.substring(0, i) === wordDict[j]) {
        // console.log(s, s.substring(0, i), i);
        if (helper(s, wordDict, dp,  i)) {
          dp[idx ] = true;
          return true;
        }
      }
    }
  }
  dp[idx] = false;
  return false;
}
var wordBreak = function (s, wordDict) {
  let dp = new Array(s.length).fill(-1);
  return helper(s, wordDict, dp, 0);
};
let word = ["cats", "dog", "sand", "and", "cat"];
console.log(wordBreak("catsandog", word));
