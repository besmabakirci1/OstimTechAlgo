// Yugi’nin kart destesini yönetiyorsun. 
// Kullanıcı olarak kart ekleyebilir, çıkarabilir, güncelleyebilir veya deste listesini görebilirsin. 
// Bir menü aracılığıyla bazı işlemleri yapıp, bunu konsolda göstermen gerekiyor. 

/// İşlem listesi şu şekildedir.
//  1 – Kart ekle
//	2 - Kart Sil (İsimle)
//	3 - Kart İsmini Güncelle (Eski isim → Yeni isim)
// 	4 - Deste Kartlarını Görüntüle
// 	5 - Kart Savaşı Başlat (Kart Seç → Kart Seç)
// 	6 - Savaş Sonuçlarını Gör (Sıralama)
// 	7 – Çıkış

/// Her kartın şu bilgileri olacak:
//  İsim
//  Atak (ATK)
//  Defans (DEF)
//  Sağlık (Max Sağlık ve Mevcut Sağlık) (HP)
//Kazanma Sayısı (başlangıç 0)

/// Savaş Kuralları
//	Kart1 → Kart2'ye saldırır → Hasar = Kart1.ATK - Kart2.DEF
//	Eğer Hasar > 0 → Kart2 HP -= Hasar
//	Eğer Hasar ≤ 0 → Kart2 hiç zarar görmez
//	Sonra Kart2 karşı saldırı yapar (aynı hesap)
//	Kartlardan biri HP ≤ 0 olursa kaybeder
//	Kazanan kartın kazanma sayısı +1 artar
//	Savaş tek tur veya sonuna kadar sürebilir


// Dark Magician (ATK:2500) saldırıyor Kuriboh (DEF:2000)→ Hasar = 2500 - 2000 = 500 → Kuriboh HP -= 500
// Kuriboh (ATK:300) saldırıyor Dark Magician (DEF:2100)→ Hasar = 300 - 2100 = -1800 → Hasar yok

// Yukarıda örnek bir savaş görülmektedir.

// Kazanan → HP > 0 kalan kart
// Kaybeden → HP ≤ 0 olan kart
// Kazanan kartın kazanma sayısı +1

