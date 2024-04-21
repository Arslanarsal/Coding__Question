function help(idx, temp, nums, l, ans) {
  ans.push([...temp]);
  for (let i = idx; i < l; i++) {
    if (i > idx && nums[i] === nums[i - 1]) {
      continue;
    }
    temp.push(nums[i]);
    help(i + 1, temp, nums, l, ans);
    temp.pop();
  }
}

var subsetsWithDup = function (nums) {
  let ans = [];
  let l = nums.length;
  nums.sort((a, b) => a - b);
  help(0, [], nums, l, ans);
  return ans;
};

let result = subsetsWithDup([2, 2, 1]);
for (let i = 0; i < result.length; i++) {
  console.log(result[i]);
}
