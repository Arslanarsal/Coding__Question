/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
  if (s.lenght !== t.lenght) {
    return false;
  }

  s.split("").sort().join('');
  t.split("").sort().join('');

  return t === s;
};
