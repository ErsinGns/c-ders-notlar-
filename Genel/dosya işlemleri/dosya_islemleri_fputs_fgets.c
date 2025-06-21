#include <stdio.h>

// 	A- char* fgets(char *buffer,int n,FILE *f);,

// 	return değeri buradaki adres olan buffer değeridir. Hata olursa NULL pointer döner
// 	\n karakterini line by line gittiği için otomotik koyar.zaten satır sonunda \n var.Bunuda alıyor yani.
// 	f = OKUMA YAPILAN HANDLE
// 	n = KAC ADET OKUMA YAPILACAĞI
// 	buffer = BU OKUMANIN YAZILACAĞI DİZİ.

// 	NOT: ÇOK ÖNEMLİ !!!!!!!
// 	EĞER BUFFER SİZE DAN DAHA KÜÇÜK BİR KARAKTER OKURSA, DATAYI OKUR BUFFERA YAZAR VE SONUNA \n DEĞİL \0 KOYAR.
// 	KISACA, \n KARAKTERİNE KADAR OKURSA BUNUDA ALIR, AMA \n KARAKTERİ YOKSA VE BUFFER DOLDUYSA SONA \0 KOYAR.



// 	B- int fputs(char *buffer,FILE *f);
// 	return değeri başarılı ise non-negative değer. Hata durumunda EOF
// 	buffer = buradaki dizileri alır
// 	f = buradaki handle a line olarak girer.

int main(int argc, char const *argv[])
{
    FILE* f = fopen("metin1.txt", "w");
    if(f == NULL){
        perror("dosya acilamadi.");
        return 1;
    }

    const char* text = "kus \nneden ucar";
    if(fputs(text, f) == EOF){
        perror("yazma hatasi");
        fclose(f);
        return 1;
    }
    fclose(f);

    FILE* file = fopen("metin1.txt", "r");
    if(file == NULL){
        perror("dosya acilamadi.");
        return 1;
    }

    char buffer[100];
    if(fgets(buffer, sizeof(buffer), file) != NULL){// sadece \n kısmına kadar okur 
        printf("okunan dizi: %s", buffer);
    }else{
        perror("okuma hatasi.");
    }
    fclose(file);


    return 0;
}

