# Anti-Hook tekniği
Malware analistler bazen kullanılan anti-analiz tekniklerini bypass etmek için kontrolleri gerçekleştiren fonksiyonları hooklayıp fonksiyonu etkisiz hale getirirler.
Library hook adlı yöntem hakkında daha detaylı bilgi için blog yazıma göz atabilirsiniz: [Link](http://www.robindimyanoglu.com/2016/07/linuxta-library-hooking-yontemi.html)

Linux'ta library hook yapmak için kullanılan yöntemlerden biri **LD_PRELOAD** ortam değişkenidir. Hook library oluşturulduktan sonra dosyanın konumu bu ortam değişkenine yüklenerek program çalıştırıldığında asıl fonksiyonlar geçersiz kılınır.

Bu ortam değişkeninin değerini elde etmek için C'deki *getenv()* fonksiyonu kullanılabilir. Şayet bu fonksiyon NULL'dan farklı bir değer döndürürse bu ortam değişkeninin içinde bir değer olduğuna yani library hook yapıldığına işarettir.
