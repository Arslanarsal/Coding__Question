var expect = function (val) {
  function toBe(v) {
    if (val === v) {
      return true;
    }
    throw new Error("Not Equal");
  }

  function notToBe(v) {
    if (val !== v) {
      return true;
    }
    throw new Error("Equal");
  }
  return {
    toBe,
    notToBe,
  };
};
// If the condition is not met, and you replace the next line with `return` instead of `throw`,
// it will just return from the function and continue execution rather than throwing an error
