# Anti-Ptrace tekniği
Analizlerde sıkça kullanılan yöntemlerden bir tanesi *debugging* dir. Debugger adı verilen araçlar bize herhangi bir programı en ince ayrıntısına kadar inceleme fırsatı verir. Programı disassemble etme, *breakpoint* koyarak programın çalışmasını istediğimiz noktada durdurma, herhangi bir anda registerların değerini görme/değiştirme, programa ait bellek alanını inceleme gibi oldukça işe yarayan özellikleri bulunur.

Peki nasıl oluyorda bir programın çalışmasına bu denli müdahale edebiliyoruz derseniz, tam bu noktada **process tracing** konusu devreye giriyor. Bu işlem için Linux'da *ptrace* adlı bir sistem çağrısı bulunmakta. Linux ortamında debuggerlar bu sistem çağrısını kullanarak işlemi takip ederler. **Bir program aynı anda tek bir process tarafından trace edilebilir!**

Bu tekniğin mantığı programın parent process'e **TRACEME** sinyali yollayarak kendisini trace ettirmeye çalışmasını sağlamaktır. Şayet program halihazırda bir debugger tarafından trace ediliyorsa bu çağrı başarısız olacaktır. Böylece debugger kullanıldığını anlayabiliriz.
