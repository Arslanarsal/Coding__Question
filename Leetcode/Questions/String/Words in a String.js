/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function (s) {
  let str = "";
  s.trim()
    .split(" ")
    .reverse()
    .forEach((ele) => {
        console.log(ele);
      if (ele) {
        str += ele + " ";
      }
    });
  return str.trim();
};

console.log(reverseWords("the sky is    blue"));
