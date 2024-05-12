const solve = (str) => {
  let i = "a";
  let arr = str.split("");
  let count = arr.reduce((acc, cur) => {
    if (cur === i) {
      acc++;
    }
    return acc;
  }, 0);
  console.log(count);
};

// let str = "my name is arslan from university of gujrat";
let str = "my name is arslan from university of gujrat";
solve(str);
