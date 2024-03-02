// var compose = function (functions) {
//   return function (x) {
//     for (let index = functions.length-1; index >= 0; index--) {
//         x =  functions[index](x);

//     }
//     return x;
//   };
// };

var compose = function (functions) {
  return function (x) {
    return functions.reduceRight((acc, currf) => currf(acc), x);
  };
};
