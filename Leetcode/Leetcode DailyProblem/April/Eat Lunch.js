/**
 * @param {number[]} students
 * @param {number[]} sandwiches
 * @return {number}
 */
var countStudents = function (students, sandwiches) {
  let arr = new Array(2).fill(0);
  let n = students.length;
  for (let i = 0; i < n; i++) {
    arr[students[i]]++;
  }
  for (let i = 0; i < n; i++) {
    let sand = sandwiches[i];

    if (arr[sand] == 0) {
      return n - i;
    }
    arr[sand]--;
  }
  return 0;
};
