# Anti-Breakpoint tekniği
Analistler bir programı debug ederken programın belirli noktalarına **breakpoint** koyarak istenilen noktalarda durmasını sağlar ve programın o anki durumunu incelerler. Bu tekniğin mantığı hafızayı tarayarak breakpointlerin varlığını tespit ederek programın debug edilip edilmediğini anlamaktır.

Breakpoint koymanın yollarından biri **int 3** instruction'ı kullanmaktır. Bu instruction çalıştığında kernel'a **SIGTRAP** sinyali yollanıp programın çalışması durdurulur. Programın durmasını istediğimiz yere **int 3** instructionının opcode'u olan *0xcc* değerini yazarak breakpoint koymuş oluruz.

Bu programda ilk fonksiyonun adresinden son fonksiyonun adresine kadar olan bellek alanı taranarak *0xcc* değerinin var olup olmadığına bakılır.
