/**
 *  In JavaScript, functions have a reference to all variables declared in the same scope as well as any outer scopes. These scopes are known as the function's lexical environment. The combination of the function and it's environment is known as a closure.
 *
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function (n) {
  return function () {
    return n++;
  };
};

const counter = createCounter(10);
counter(); // 10
counter(); // 11
counter(); // 12

class Adder {
  constructor(a) {
    this.a = a;
  }

  add(b) {
    const sum = this.a + b;
    return sum;
  }
}
const addTo2 = new Adder(2);
addTo2.add(5); // 7
