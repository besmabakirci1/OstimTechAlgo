// Verilen bir dizide yalnızca bir kere geçen elemanları listeleyin.

const FindOnce = (arr) => { // fonk ismi bulamadım
    const counts = new Map(); //  key-value ları saklamak icin
  
    for (const item of arr) {
      counts.set(item, (counts.get(item) || 0) + 1); // eğer sayı mapte varsa onun sayısı alınır, yoksa 0'dan başlar. +1 eklenir.
    }
  
    const tekOlanlar = []; // sonuçlar için
    for (const [item, count] of counts.entries()) { // burada counts'u key value olacak şeklinde döngü başlatıyorum
      if (count === 1) { // 1 defa geçenleri
        tekOlanlar.push(item); // arraye alıyorum
      }
    }
  
    return tekOlanlar; // tek olanları return ediyorum
  };
  
  const numbers = [1, 2, 2, 3, 4, 4, 12435];
  console.log("Tek elamanlar:", FindOnce(numbers));
  