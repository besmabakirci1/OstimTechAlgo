// Kullanıcıdan alınan bir dizinin palindrom olup olmadığını kontrol edin.

// Palindrom nedir? Palindrom, tersten okunuşu da aynı olan kelime, sayı veya dizilere denir.

const isPalindrome = (arr) => {
    for (let i = 0; i < arr.length / 2; i++) { // ortasına kadar kontrol ettim
      if (arr[i] !== arr[arr.length - 1 - i]) { // sonundaki karşıtı ile karşılaştırdım
        return false; // değilse false döndüm
      }
    }
    return true; // öyleyse true döndüm
  };
  
  const input = [1, 2, 3, 2, 1];
  console.log("palindrom mu", isPalindrome(input));
  