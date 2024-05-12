/**
 * @param {number[]} people
 * @param {number} limit
 * @return {number}
 */
var numRescueBoats = function (people, limit) {
  people.sort((a, b) => a - b);
  let n = people.length;
  let ans = 0;
  let i = 0,
    j = n - 1;
  while (i <= j) {
    if (people[i] + people[j] <= limit) {
      left++;
    }
    j--;
    ans++;
  }
  return ans;
};
