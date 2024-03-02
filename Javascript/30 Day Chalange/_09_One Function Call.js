var once = function (fn) {
  let flag = true;
  return function (...args) {
    if (flag) {
      flag = false;
      return fn(...args);
    }
    return undefined;
  };
};
