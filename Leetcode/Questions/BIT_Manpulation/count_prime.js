/**
 * @param {number} n
 * @return {number}
 */
var countPrimes = function (n) {
  if (n < 2) return 0;
  let prime = new Array(n + 1).fill(1);
  for (let i = 2; i * i <= n; i++) {
    if (prime[i]) {
      for (let j = i * i; j <= n; j += i) {
        prime[j] = 0;
      }
    }
  }
  let ans = 0;
  for (let j = 2; j <= n; j++) {
    if (prime[j]) {
      ans++;
    }
  }
  return ans;
};
