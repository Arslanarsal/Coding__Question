var filter = function (arr, fn) {
  let ans = [];
  for (let i = 0; i < arr.length; i++) {
    let flag = fn(arr[i], i);
    if (flag == true) {
      ans.push(arr[i]);
    }
  }
  return ans;
};
