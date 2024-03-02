var reduce = function (nums, fn, init) {
  let ans = init;
  for (const i of nums) {
    ans = fn(ans, i);
  }
  return ans;
};
