# Anti-VM tekniği (Virtual PC için)
Zararlı yazılımlar analiz edilirken bilgisayara zarar vermemesi için sanal makine üzerinde çalıştırılıp analiz o şekilde gerçekleştirilir. Bu durumu bilen malware developerlar zararlı yazılımlarını sanal makine içerisinde çalıştırıldığını tespit edecek şekilde geliştirdiler. Şayet sanal makine üzerinde çalıştırılıyorsa program zararlı bir aktivitede bulunmayarak analisti yanıltmaya çalışır. Bu tekniklerin tümüne **Anti-VM** adı verilir.

Bu Anti-VM tekniklerinden bazıları şurada açıklanmıştır: [Link](https://blog.malwarebytes.com/threat-analysis/2014/09/five-anti-debugging-tricks-that-sometimes-fool-analysts/)

Bu yazıda yer alan 2 no'lu tekniği uygulayalım. Bu teknik Microsoft Virtual PC sanallaştırma yazılımını hedef alır. Mantığı bu yazılıma özel instructionları program içerisinde kullanarak çalışıp çalışmadığına bakmaktır. Şayet bu program Virtual PC üzerinde çalıştırılırsa özel instructionlar başarıyla çalışacak, aksi takdirde program **Illegal Instruction** hatası verecektir. Bu hata program tarafından yakalanıp hata oluştuğu takdirde zararlı kodlar çalıştırılmalıdır.

Programda *mmap()* ile çalıştırılabilir bellek alanı ayırılıp Virtual PC instructionları bu alana yüklendi. Ardından bu kodlar çalıştırılıp *signal()* fonksiyonu ile **SIGILL** (illegal instruction) sinyali yakalanmıştır.
