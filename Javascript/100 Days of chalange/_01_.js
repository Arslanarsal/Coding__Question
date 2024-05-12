const findLongestWord = (str) => {
  let arr = str.split(" ");

  //   arr = arr.sort((a, b) => a.length - b.length);
  let a = arr.reduce((acc, cur) => (cur.length > acc.length ? cur : acc), "");

  console.log(a); // Log the longest word
};

let str = "my name is arslan from university of gujrat";
findLongestWord(str);
