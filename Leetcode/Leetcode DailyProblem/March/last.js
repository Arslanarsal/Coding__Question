/**
 * @param {number[]} nums
 * @param {number} minK
 * @param {number} maxK
 * @return {number}
 */
var countSubarrays = function (nums, minK, maxK) {
  let maxele = -1;
  let minele = -1;
  let colele = -1;
  let n = nums.length;
  let ans = 0;

  for (let i = 0; i < n; i++) {
    if (nums[i] < minK || nums[i] > maxK) {
      colele = i;
    }

    if (nums[i] == minK) {
      minele = i;
    }
    if (nums[i] == maxK) {
      maxele = i;
    }

    let k = Math.min(maxele, minele);

    let ad = k - colele;

    ans += ad > 0 ? ad : 0;
  }
  return ans;
};
