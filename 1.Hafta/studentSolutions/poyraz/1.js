// Bir tamsayı dizisi verildiğinde, dizideki en küçük elemanı bulun.

const numbers = [23, 5, 89, -3, 0, 12];

const findMin = (arr) => {
  if (arr.length === 0) return null; // Eğer dizi boş gelirse null dönüyorum
  let min = arr[0]; // min değeri önce 0. indeks kabul ediyorum
  for (let i = 1; i < arr.length; i++) { // her bir daha küçük bulduğumda en küçük sayım o oluyor
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  return min; // en sona kalan yani en küçüğü return ediyorum.
};

console.log("En küçük sayı:", findMin(numbers)); // cd 1.Hafta studentSolutions poyraz ---> node 1.js
