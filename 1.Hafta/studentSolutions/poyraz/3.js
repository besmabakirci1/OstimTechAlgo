// Bir dizideki tüm elemanların toplamını hesaplayın.

const sumElements = (arr) => {
    let total = 0;
    for (let i = 0; i < arr.length; i++) {
      total += arr[i];
    }
    return total;
  };
  
  const numbers = [5, 10, 15, 20];
  console.log("Toplam:", sumElements(numbers));
  