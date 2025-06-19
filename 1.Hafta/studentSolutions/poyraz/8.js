// Verilen bir dizide yinelenen (duplicate) elemanları bulun.

const findDuplicate = (arr) => {
    const seen = new Set(); // görülen sayıları tutacağım
    const duplicates = new Set(); // tekrar edenleri toplayacağım
  
    for (const item of arr) { // elemanları dolaşıyorum
      if (seen.has(item)) { // eğer seen içinde varsa
        duplicates.add(item); // duplicate içine ekliyorum
      } else { // yoksa
        seen.add(item); // seen e ekliyorum (ilk başta buraya eklenmeye başlıyor, sonra tekrar görülürse duplicate e dönüyor)
      }
    }
  
    return Array.from(duplicates); // arraya çevirdim
  };
  
  const numbers = [2, 3, 2, 4, 5, 1, 6, 3, 2, 2, 4, 3, 3];
  console.log("Duplicates:", findDuplicate(numbers));
  