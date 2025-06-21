// paralel programlama c de var öğren bu kursta anlatmıyor

// işlemcinin farklı korları farklı işlemler yapıyor 

// fscanf(f, "%d", &x) bosluğa kadar alır scanf gibi ama sitandart girişten değil dosyadan alır
#include <stdio.h>

int main(int argc, char **argv)
{
	FILE* fd, * fs;

	if (argc != 3)
	{
		fprintf(stderr, "dogru kullanim <encr> <program.exe> <anahtar>");
		return 1;
	}

	if ((fs = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "%s dosya acilamadi\n",argv[1]);
		return 2;
	}

	char temp_filename[L_tmpnam];
	tmpnam(temp_filename);

	//hiçbir dosyayı ezmeyecek şekilde dosyayı açıyoruz.

	if ((fd = fopen(temp_filename, "wb")) == NULL)
	{
		fprintf(stderr, "Dosya acilamadi\n");
		return 3;
	}

	//BURADAN SONRASI BAYA ÖNEMLİ
	int seed = atoi(argv[2]);
	srand((unsigned int)seed);

	int c;

	while ((c = fgetc(fs)) != EOF)
	{
		fputc(c ^ rand(), fd);
	}

	fclose(fs);
	fclose(fd);

	if (remove(argv[1]))
	{
		fprintf(stderr, "dosya silinemedi\n");
		return 4;
	}

	if (rename(temp_filename, argv[1]))
	{
		fprintf(stderr, "Dosya isim degisikligi yapilamadi\n");
		return 5;
	}

	//.\encr.exe .\say.exe 123456
	// .\say.exe		artık çalışmayacak.

	// decrypt ediyorum.
	// .\encr.exe .\say.exe 123456
	// .\say.exe artık çalışıyor.

}