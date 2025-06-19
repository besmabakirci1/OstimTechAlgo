// Bir dizinin tüm elemanlarını ekrana yazdıran bir fonksiyon yazın.

const printArray = (arr) => {
    arr.forEach((element) => { // foreach ile döndüm, alternatifinde length ile dönülüp yazdırılabilir.
      console.log(element);
    });
  };
  
  const numbers = [1, 2, 3, 4, 5];
  printArray(numbers);
  