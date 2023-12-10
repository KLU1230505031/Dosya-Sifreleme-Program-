#include <stdio.h>
#include <stdlib.h>


//sifreleme fonksiyonumuz 
void sifrele(FILE *girisDosya, FILE *cikisDosya, int anahtar) { 
    int karakter;

    while ((karakter = fgetc(girisDosya)) != EOF) {    //girisdosya sýndaki her karakteri anahtar kadar kaydýrarak sifreler
        karakter = karakter + anahtar;
        fputc(karakter, cikisDosya);
    }
}

//sifreyi cözme fonksiyonumuz
void sifrecoz(FILE *girisDosya, FILE *cikisDosya, int anahtar) {
    int karakter;

    while ((karakter = fgetc(girisDosya)) != EOF) {    //giris dosyasýndaki sifreleli karakterleri anahatar kadar geri kaydýrýr ve sifre cözülür
        karakter = karakter - anahtar;
        fputc(karakter, cikisDosya);
    }
}

int main() {
    FILE *girisdosyasi, *sifrelidosya, *cozulmusdosya; // dosyalarýmýzý tanýmlýyoruz 
    char girisdosyasiAdi[] = "input1.txt"; // sifrelenecek dosyamýz
    char sifrelidosyaAdi[] = "sifreli.txt";
    char cozulmusdosyaAdi[] = "cozulmus.txt";
    int anahtar;  
	
	 printf("anahtar degerini giriniz:\n");scanf("%d",&anahtar); //kullanýcýdan anahtar degeri alýyoruz
    
    girisdosyasi = fopen(girisdosyasiAdi, "r"); // Dosyayý aç
    if (girisdosyasi == NULL) {   //giris dosyamýz yoksa dosya acma hatasý olarak bize geri dönus verir
        printf("Dosya acma hatasi");
        return 1;
    }

    // Þifrele ve þifrelenmiþ dosyayý kaydet
    sifrelidosya = fopen(sifrelidosyaAdi, "w");
    sifrele(girisdosyasi, sifrelidosya, anahtar);
		
	printf("dosya sifrelenmistir ve 'sifreli.txt'olarak kaydedilmistir.\n");


    
    fclose(girisdosyasi);//girisdosyasini kapat
    fclose(sifrelidosya);//sifrelidosyayý kapat

    
    sifrelidosya = fopen(sifrelidosyaAdi, "r"); // Þifrelenmiþ dosyayý aç
    if (sifrelidosya == NULL) {   //sifreli dosyamýz yoksa dosya acma hatasý olarak bize geri dönus verir
        printf("Dosya acma hatasi");
        return 1;
        
    }

    // Þifreyi çöz ve çözülmüþ dosyayý kaydet
    cozulmusdosya = fopen(cozulmusdosyaAdi, "w");
    sifrecoz(sifrelidosya, cozulmusdosya, anahtar); 

    printf(" sifreli dosyamiz cozulmustur ve 'cozulmus.txt'olarak kaydedilmitir.\n");

    
    fclose(sifrelidosya);//sifrelidosyayý kapat
    fclose(cozulmusdosya);//cozulmusdosyayý kapat

	
	
    printf("Sifreleme ve Cozme islemi basariyla tamamlanmistir.\n");

    return 0;
}
