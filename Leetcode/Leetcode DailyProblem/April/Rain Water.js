var trap = function (height) {
  let n = height.length;
  let leftmax = height[0],
    rightmax = height[n - 1];
  let left = 0,
    right = n - 1;
  let ans = 0;
  while (left < right) {
    while (left < right && leftmax <= rightmax) {
      leftmax = Math.max(leftmax, height[left]);
      let ansminus = Math.min(leftmax, rightmax);
      ansminus = ansminus - height[left];
      if (ansminus >= 0) {
        ans = ans + ansminus;
        left++;
      }
    }
    console.log(left, ans, leftmax);

    while (left < right && rightmax <= leftmax) {
      rightmax = Math.max(rightmax, height[right]);
      let ansminus = Math.min(leftmax, rightmax);
      ansminus = ansminus - height[right];
      if (ansminus >= 0) {
        ans = ans + ansminus;
        right--;
      }
    }
    console.log(right, ans, rightmax);
  }
  return ans;
};

let arr = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1];
console.log(trap(arr));
