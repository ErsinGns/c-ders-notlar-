#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// İş parçacığının çalıştıracağı fonksiyon
void* print_numbers(void* arg) {
    for (int i = 1; i <= 5; i++) {
        printf("Sayı: %d\n", i);
        sleep(1); // 1 saniye bekle
    }
    return NULL;
}

void* print_letters(void* arg) {
    for (char letter = 'A'; letter <= 'E'; letter++) {
        printf("Harf: %c\n", letter);
        sleep(1); // 1 saniye bekle
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // İş parçacıklarını oluştur ve çalıştır
    pthread_create(&thread1, NULL, print_numbers, NULL);
    pthread_create(&thread2, NULL, print_letters, NULL);

    // Ana iş parçacığı diğer iş parçacıklarının bitmesini bekler
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Her iki iş parçacığı da tamamlandı!\n");

    return 0;
}
