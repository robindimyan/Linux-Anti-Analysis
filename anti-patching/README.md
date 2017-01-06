# Anti-Patching tekniği
Analistler inceledikleri bir programda bulunan kontrolleri aşmak adına programda bazı yerleri modifiye edip bu kontrolleri bypass edebilirler. Bu yönteme *binary modification* veya *patching* adı verilir. Anti-patching tekniğinin mantığı program çalışmaya başlamadan önce kodların **checksum** değerini hesaplayıp önceden hesaplanmış esas checksum değeri ile karşılaştırarak programın değiştirilip değiştirilmediğini bulmaya çalışmaktır.

Orijinal checksum değerinin depolandığı yer checksum hesabını etkilememesi adına *text* segmentinden farklı bir segmentte bulunmalıdır. Dolayısıyla örnek programda bu değeri depolayacak değişken *static char* olarak belirlenmiştir. Bu değer debugger aracılığıyla bulunabilir veya elle opcode değerlerinin toplanması yoluyla hesaplanabilir. Checksum hesabı için de çok basit bir algoritma kullanılmıştır.

**NOT:** Örnek kodda kullanılan yöntem aynı zamanda *int 3* yoluyla koyulan breakpointleri de tespit edebilmektedir.
