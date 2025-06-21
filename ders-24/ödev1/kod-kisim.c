// kelime değiş
for(int j = 0; j < k2; j++){
        int harf;
        printf("[%s]\n", str);
        if(str[kelime2] == '\0')
            harf = ' ';
        else{
            harf = str[kelime2];
        }
        str[kelime2] = str[j];
        str[j] = harf;
        kelime2++;
    }
    str[--kelime2] = '\0';



    kelime değiş

     while(kelime_2_uzunluk--){
        for(int j = kelime_1_uzunluk; str[j - 1]; j--){
        int harf = str[j];
        str[j] = str[j - 1];
        str[j - 1 ] = harf;
    }
    printf("[%s]\n", str);
    
    }
    for(int i = kelime_1_uzunluk; str[i]; i++){
        int sabit = kelime_1_uzunluk;
        while (sabit)
        {
            int harf = str[i];
            str[i] = str[i - 1];
            str[i - 1] = harf;
            sabit--;
        }
        printf("[%s]\n", str);

    }

       int max_ending_here = a[0];
    int max_so_far = a[0];

    for (int i = 1; i < SIZE; i++) {
        max_ending_here = (a[i] > max_ending_here + a[i]) ? a[i] : max_ending_here + a[i];
        max_so_far = (max_so_far > max_ending_here) ? max_so_far : max_ending_here;
        printf("%d %d %d\n",a[i], max_ending_here, max_so_far);
        getchar();
    }
    printf("%d", max_so_far);
