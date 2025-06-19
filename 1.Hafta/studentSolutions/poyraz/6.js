// Bir dizi verildiğinde, dizideki tüm elemanları ters çevirin (reverse).

const reverseArray = (arr) => {
    return arr.slice().reverse();
  };
  
  const numbers = [1, 2, 3, 4, 5];
  console.log("Reversed array:", reverseArray(numbers));


/*
const reverseArray = (arr) => {
  const result = [];
  for (let i = arr.length - 1; i >= 0; i--) {
    result.push(arr[i]);
  }
  return result;
};

const numbers = [1, 2, 3, 4, 5];
console.log("Reversed array:", reverseArray(numbers));
*/