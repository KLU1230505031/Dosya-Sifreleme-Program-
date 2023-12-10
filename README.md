#include <stdio.h>
#include <stdlib.h>


//sifreleme fonksiyonumuz 
void sifrele(FILE *girisDosya, FILE *cikisDosya, int anahtar) { 
    int karakter;

    while ((karakter = fgetc(girisDosya)) != EOF) {    //girisdosya sındaki her karakteri anahtar kadar kaydırarak sifreler
        karakter = karakter + anahtar;
        fputc(karakter, cikisDosya);
    }
}

//sifreyi cözme fonksiyonumuz
void sifrecoz(FILE *girisDosya, FILE *cikisDosya, int anahtar) {
    int karakter;

    while ((karakter = fgetc(girisDosya)) != EOF) {    //giris dosyasındaki sifreleli karakterleri anahatar kadar geri kaydırır ve sifre cözülür
        karakter = karakter - anahtar;
        fputc(karakter, cikisDosya);
    }
}

int main() {
    FILE *girisdosyasi, *sifrelidosya, *cozulmusdosya; // dosyalarımızı tanımlıyoruz 
    char girisdosyasiAdi[] = "input1.txt"; // sifrelenecek dosyamız
    char sifrelidosyaAdi[] = "sifreli.txt";
    char cozulmusdosyaAdi[] = "cozulmus.txt";
    int anahtar;  
	
	 printf("anahtar degerini giriniz:\n");scanf("%d",&anahtar); //kullanıcıdan anahtar degeri alıyoruz
    
    girisdosyasi = fopen(girisdosyasiAdi, "r"); // Dosyayı aç
    if (girisdosyasi == NULL) {   //giris dosyamız yoksa dosya acma hatası olarak bize geri dönus verir
        printf("Dosya acma hatasi");
        return 1;
    }

    // Şifrele ve şifrelenmiş dosyayı kaydet
    sifrelidosya = fopen(sifrelidosyaAdi, "w");
    sifrele(girisdosyasi, sifrelidosya, anahtar);
		
	printf("dosya sifrelenmistir ve 'sifreli.txt'olarak kaydedilmistir.\n");


    
    fclose(girisdosyasi);//girisdosyasini kapat
    fclose(sifrelidosya);//sifrelidosyayı kapat

    
    sifrelidosya = fopen(sifrelidosyaAdi, "r"); // Şifrelenmiş dosyayı aç
    if (sifrelidosya == NULL) {   //sifreli dosyamız yoksa dosya acma hatası olarak bize geri dönus verir
        printf("Dosya acma hatasi");
        return 1;
        
    }

    // Şifreyi çöz ve çözülmüş dosyayı kaydet
    cozulmusdosya = fopen(cozulmusdosyaAdi, "w");
    sifrecoz(sifrelidosya, cozulmusdosya, anahtar); 

    printf(" sifreli dosyamiz cozulmustur ve 'cozulmus.txt'olarak kaydedilmitir.\n");

    
    fclose(sifrelidosya);//sifrelidosyayı kapat
    fclose(cozulmusdosya);//cozulmusdosyayı kapat

	
	
    printf("Sifreleme ve Cozme islemi basariyla tamamlanmistir.\n");

    return 0;
}
