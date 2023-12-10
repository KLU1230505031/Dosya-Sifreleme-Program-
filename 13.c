#include <stdio.h>
#include <stdlib.h>


//sifreleme fonksiyonumuz 
void sifrele(FILE *girisDosya, FILE *cikisDosya, int anahtar) { 
    int karakter;

    while ((karakter = fgetc(girisDosya)) != EOF) {    //girisdosya s�ndaki her karakteri anahtar kadar kayd�rarak sifreler
        karakter = karakter + anahtar;
        fputc(karakter, cikisDosya);
    }
}

//sifreyi c�zme fonksiyonumuz
void sifrecoz(FILE *girisDosya, FILE *cikisDosya, int anahtar) {
    int karakter;

    while ((karakter = fgetc(girisDosya)) != EOF) {    //giris dosyas�ndaki sifreleli karakterleri anahatar kadar geri kayd�r�r ve sifre c�z�l�r
        karakter = karakter - anahtar;
        fputc(karakter, cikisDosya);
    }
}

int main() {
    FILE *girisdosyasi, *sifrelidosya, *cozulmusdosya; // dosyalar�m�z� tan�ml�yoruz 
    char girisdosyasiAdi[] = "input1.txt"; // sifrelenecek dosyam�z
    char sifrelidosyaAdi[] = "sifreli.txt";
    char cozulmusdosyaAdi[] = "cozulmus.txt";
    int anahtar;  
	
	 printf("anahtar degerini giriniz:\n");scanf("%d",&anahtar); //kullan�c�dan anahtar degeri al�yoruz
    
    girisdosyasi = fopen(girisdosyasiAdi, "r"); // Dosyay� a�
    if (girisdosyasi == NULL) {   //giris dosyam�z yoksa dosya acma hatas� olarak bize geri d�nus verir
        printf("Dosya acma hatasi");
        return 1;
    }

    // �ifrele ve �ifrelenmi� dosyay� kaydet
    sifrelidosya = fopen(sifrelidosyaAdi, "w");
    sifrele(girisdosyasi, sifrelidosya, anahtar);
		
	printf("dosya sifrelenmistir ve 'sifreli.txt'olarak kaydedilmistir.\n");


    
    fclose(girisdosyasi);//girisdosyasini kapat
    fclose(sifrelidosya);//sifrelidosyay� kapat

    
    sifrelidosya = fopen(sifrelidosyaAdi, "r"); // �ifrelenmi� dosyay� a�
    if (sifrelidosya == NULL) {   //sifreli dosyam�z yoksa dosya acma hatas� olarak bize geri d�nus verir
        printf("Dosya acma hatasi");
        return 1;
        
    }

    // �ifreyi ��z ve ��z�lm�� dosyay� kaydet
    cozulmusdosya = fopen(cozulmusdosyaAdi, "w");
    sifrecoz(sifrelidosya, cozulmusdosya, anahtar); 

    printf(" sifreli dosyamiz cozulmustur ve 'cozulmus.txt'olarak kaydedilmitir.\n");

    
    fclose(sifrelidosya);//sifrelidosyay� kapat
    fclose(cozulmusdosya);//cozulmusdosyay� kapat

	
	
    printf("Sifreleme ve Cozme islemi basariyla tamamlanmistir.\n");

    return 0;
}
