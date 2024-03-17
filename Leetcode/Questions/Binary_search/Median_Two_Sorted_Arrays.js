/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function (nums1, nums2) {
  let n = nums1.length;
  let m = nums2.length;
  if (n > m) return findMedianSortedArrays(nums2, nums1);
  let i = 0;
  let j = n;
  let left = Math.floor((n + m + 1) / 2);
  while (i <= j) {
    let mid1 = Math.floor((i + j) / 2);
    let mid2 = left - mid1;
    let l1 = Number.MIN_SAFE_INTEGER;
    let l2 = Number.MIN_SAFE_INTEGER;
    let r1 = Number.MAX_SAFE_INTEGER;
    let r2 = Number.MAX_SAFE_INTEGER;

    if (mid1 < n) {
      r1 = nums1[mid1];
    }
    if (mid1 > 0) {
      l1 = nums1[mid1 - 1];
    }
    if (mid2 < m) {
      r2 = nums2[mid2];
    }
    if (mid2 > 0) {
      l2 = nums2[mid2 - 1];
    }

    if (l1 <= r2 && l2 <= r1) {
      if ((n + m) % 2 === 1) {
        return Math.max(l1, l2);
      }
      return (Math.max(l1, l2) + Math.min(r1, r2)) / 2;
    } else if (l1 > r2) {
      j = mid1 - 1;
    } else {
      i = mid1 + 1;
    }
  }
  return 0;
};
