const tages = (str) => {
  let arr = str.split(" ");
  arr = arr.map(
    (ele) =>
      // ele.replace(ele[0], ele[0].toUpperCase())
      ele.charAt(0).toUpperCase() + ele.slice(1)
  );
  arr = arr.join("");
  arr = `#${arr}`;

  console.log(arr);
};

const tage = (str) => {
  let arr = str.split(" ");
  arr = arr.map((ele) => {
    return ele.replace(ele[0], ele[0].toUpperCase());
  });

  console.log(arr);
};

let str = "my name is arslan from university of gujrat";
tages(str);
