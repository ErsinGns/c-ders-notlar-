
#include <stdio.h>
#include <threads.h>

int print_message(void* arg) {
    char* message = (char*) arg;
    printf("%s\n", message);
    return 0;
}

int main() {
    thrd_t thread1, thread2;
    char* message1 = "Thread 1";
    char* message2 = "Thread 2";

    thrd_create(&thread1, print_message, (void*) message1);
    thrd_create(&thread2, print_message, (void*) message2);

    thrd_join(thread1, NULL);
    thrd_join(thread2, NULL);

    return 0;
}