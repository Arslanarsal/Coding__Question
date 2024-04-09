var checkValidString = function (s) {
  let low = 0,
    high = 0;
  for (let i = 0; i < s.length; i++) {
    let c = s.charCodeAt(i); // 40: ( 41: ) 42: *
    high += c == 41 ? -1 : 1;
    if (high < 0) {
      return false;
    }
    low += c == 40 ? 1 : -1;
    if (low < 0) {
      low = 0;
    }
  }
  return low == 0;
};
