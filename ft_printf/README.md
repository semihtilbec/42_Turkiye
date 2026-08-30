*This project has been created as part of the 42 curriculum by setilbec.*

# ft_printf

## Description

`ft_printf`, C standart kütüphanesindeki `printf()` fonksiyonunun bir yeniden
uygulamasıdır. Amaç, değişken sayıda argüman alan (variadic) bir fonksiyonun
nasıl yazıldığını öğrenmek ve `printf`'in temel dönüşüm (conversion)
karakterlerini orijinaliyle birebir aynı çıktıyı üretecek şekilde kendi
başımıza implemente etmektir.

Proje, kaynak dosyalardan derlenip `ar` komutuyla statik bir kütüphane
(`libftprintf.a`) haline getirilir; bu kütüphane herhangi bir C projesine
linklenerek kullanılabilir.

Desteklenen dönüşümler (mandatory kapsamı):

| Format | Açıklama                                   |
|--------|---------------------------------------------|
| `%c`   | Tek karakter yazdırır                        |
| `%s`   | String yazdırır (`NULL` için `(null)`)       |
| `%p`   | `void *` pointer'ı hexadecimal olarak yazar  |
| `%d`   | Signed decimal (base 10) sayı                |
| `%i`   | Signed integer, base 10                      |
| `%u`   | Unsigned decimal (base 10) sayı              |
| `%x`   | Hexadecimal (base 16), küçük harf            |
| `%X`   | Hexadecimal (base 16), büyük harf            |
| `%%`   | Literal `%` karakteri                        |

Genişlik (width), hassasiyet (precision) ve bayraklar (`-`, `0`, `#`, `+`,
` `) gibi bonus özellikler bu aşamada implemente edilmemiştir.

## Instructions

### Derleme

Repo kökünden:

```bash
make          # libftprintf.a dosyasını repo kökünde üretir
```

Diğer Makefile kuralları:

```bash
make clean    # .o dosyalarını siler
make fclean   # .o dosyalarını ve libftprintf.a'yı siler
make re       # fclean + all
```

Derleme, `cc` ile `-Wall -Wextra -Werror` bayrakları kullanılarak yapılır.

### Kullanım

Kütüphaneyi kendi projenizde kullanmak için `ft_printf.h`'i include edip
`libftprintf.a`'yı linklemeniz yeterli:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Merhaba %s! Sayi: %d, hex: %x\n", "dunya", 42, 255);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o my_program
./my_program
```

### Test etme

Proje bir test binary'si içermez (subject gereği zorunlu değil), ama kendi
test dosyanızı yazıp `libftprintf.a`'ya linkleyerek çıktıyı orijinal
`printf()` ile karşılaştırabilirsiniz:

```c
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    ft_printf("%s - %d - %x\n", "test", -42, 255);
    printf ("%s - %d - %x\n", "test", -42, 255);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror test.c -L. -lftprintf -o test
./test
```

## Algorithm & Data Structures

`ft_printf`, format string'i tek geçişte (single pass) karakter karakter
tarayan basit bir state machine olarak tasarlanmıştır; ek bir veri yapısına
ihtiyaç duyulmaz:

- **Parsing (`ft_printf.c`)**: `format` dizisi baştan sona dolaşılır. Bir `%`
  karakteri, geçerli bir dönüşüm karakteriyle (`is_format`) devam ediyorsa
  `check_format()` çağrılır ve `va_list` üzerinden ilgili tipteki argüman
  (`va_arg`) çekilip doğru yazdırma fonksiyonuna yönlendirilir. Aksi halde
  karakter olduğu gibi yazdırılır. Fonksiyon, yazılan toplam karakter
  sayısını döndürerek gerçek `printf()`'in dönüş değeri davranışını taklit
  eder.
- **Recursive sayı yazdırma (`ft_print_nbr.c`, `ft_print_unsigned.c`,
  `ft_print_hex.c`)**: Sayılar, en anlamlı basamaktan başlayarak yazdırılmak
  zorunda olduğu için (örn. 123 → önce '1', sonra '2', sonra '3'), her
  fonksiyon `n >= taban` olduğu sürece kendini `n / taban` ile tekrar çağırır,
  sonra `n % taban`'ı yazdırır. Bu, ekstra bir buffer/dizi tutmadan doğru
  sırada çıktı almayı sağlar.
- **`INT_MIN` özel durumu**: `ft_print_nbr`, `int` parametresini `long`'a
  atayarak negatifse işaretini çevirir. `long` tipi `int`'ten geniş
  olduğundan (64-bit sistemlerde), `-INT_MIN` taşma (overflow) yaşamadan
  hesaplanabilir.
- **Pointer yazdırma (`ft_print_ptr.c`)**: Adres `unsigned long long`'a cast
  edilip `0x` öneki eklenerek hex yazdırma fonksiyonuna devredilir; `NULL`
  özel olarak `(nil)` yazdırır.
- Buffer yönetimi (subject'in yasakladığı gibi) implemente edilmemiştir; her
  karakter doğrudan `write(1, ...)` ile yazılır.

## Resources

- 42 `ft_printf` subject PDF (proje gereksinimlerinin birincil kaynağı)
- `man 3 printf` — orijinal `printf` davranışını referans almak için
- [cppreference.com — Variadic functions / `<stdarg.h>`](https://en.cppreference.com/w/c/variadic)
- 42 Norm dokümantasyonu

**AI kullanımı:** Bu projenin `ft_printf` mantığı (parsing, recursive sayı
yazdırma, hex/pointer/string yardımcı fonksiyonları) tarafımdan yazıldı. Bir
yapay zeka asistanı (Claude, Claude Code üzerinden) şu görevler için
kullanıldı:

- Yazılan kodun subject gereksinimleriyle (desteklenen conversion'lar,
  `-Wall -Wextra -Werror`, Makefile kuralları, kütüphane ismi/konumu) satır
  satır karşılaştırılması ve derlemeyi kıran hataların tespiti (eksik
  `#include`, `check_format()` içinde eksik `return`, header'da eksik
  `ft_printf` prototipi).
- `Makefile`'daki `SRCS` listesine yanlışlıkla eklenmiş `ft_printf.h`'in
  `make clean` sırasında header dosyasını silen bir hataya yol açtığının
  tespiti ve düzeltilmesi.
- Gerçek `printf()` ile birebir karşılaştırmalı otomatik testler yazılıp
  çalıştırılarak (farklı `%c %s %p %d %i %u %x %X %%`, `NULL`, `INT_MIN`
  senaryoları) çıktı/dönüş değeri doğruluğunun doğrulanması.
- Bu README dosyasının taslağının hazırlanması.

Kod, algoritma tasarımı ve tüm düzeltmelerin uygulanma kararı bana ait;
AI doğrudan çözüm kodu üretmek yerine gözden geçirme, hata tespiti ve
test/dogrulama amacıyla kullanıldı.
