/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function (init) {
  let n = init;
  function increment() {
    return ++n;
  }
  function reset() {
    return (n = init);
  }
  function decrement() {
    return --n;
  }
  return {
    increment,
    reset,
    decrement,
  };
};

const counter = createCounter(5);
console.log(counter.increment()); // 6
console.log(counter.reset()); // 5
console.log(counter.decrement()); // 4
