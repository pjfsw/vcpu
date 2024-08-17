#include "cpu.h"
#include "core_risc16.h"
#include <stdio.h>
#include <signal.h>
#include <stdbool.h>
#include <time.h>

static volatile bool running = true;

void int_handler(int dummy) {
    running = false;
}

int main(int argc, char **argv) {
    printf("vcpu v0.01\n");
    Core *core = core_risc16_create();
    Cpu *cpu = cpu_create(core);
    signal(SIGINT, int_handler);
    struct timespec ts;
    ts.tv_nsec = 100000000;
    ts.tv_sec = 0;
    while (running) {
        cpu_next(cpu);
        nanosleep(&ts, NULL);
    }
    printf("vcpu done, ran %d cycles\n", cpu->cycle);
    cpu_destroy(cpu);   

}
