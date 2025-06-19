// Verilen bir dizideki çift sayıların ortalamasını hesaplayın.

const ortalamaSayı = (arr) => {
    const evens = arr.filter(num => num % 2 === 0); // çift sayıları filtreliyoruz
    if (evens.length === 0) return 0; // dizi uzunluğu 0 sa boş döndürüyoruz
    const sum = evens.reduce((acc, val) => acc + val, 0); // reduce metodunu kullanmadan da forEach ile gezip += ile 
    return sum / evens.length;
  };
  
  const numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
  console.log("Sayıların ortalaması:", ortalamaSayı(numbers));
  