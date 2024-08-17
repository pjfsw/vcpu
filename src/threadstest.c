#include <stdbool.h>
#include <stdio.h>
#include <threads.h>
#include <time.h>
#include <unistd.h>


typedef struct {
    volatile int foo;
    volatile bool done;
} Data;

Data data;

int test_func(void *user_data) {
    Data *data = (Data *)user_data;
    struct timespec ts;

    ts.tv_sec = 0;
    ts.tv_nsec = 100000000;

    while (!data->done) {
        printf("Foo is %d\n", data->foo);
        thrd_sleep(&ts, NULL);
    }
    return 0;
}

int test_threads() {
    thrd_t thrd;

    data.done = false;
    data.foo = 0;

    if (thrd_success != thrd_create(&thrd, test_func, &data)) {
        fprintf(stderr, "Failed to create thread\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        data.foo = i;
        sleep(1);
    }
    data.done = true;
    int result;
    thrd_join(thrd, &result);
    printf("Thread returned %d\n", result);

    return 0;
}
