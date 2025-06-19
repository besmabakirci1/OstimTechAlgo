// Bir dizide belirli bir sayının kaç kere geçtiğini bulun.

const countNumbers = (arr, target) => {
    let count = 0;
    for (let i = 0; i < arr.length; i++) {
      if (arr[i] === target) {
        count++;
      }
    }
    return count;
  };
  
  const numbers = [2, 5, 2, 7123, 2, 23, 42, 653, 86];
  const target = 2;
  
  console.log(`${target} sayısı dizide ${countNumbers(numbers, target)} kere geçiyor hocam.`);
  