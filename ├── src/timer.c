#include <unistd.h>
#include <time.h>
#include "timer.h"

static struct timespec start_time;
static int interval;

void timerInit(int tick) {
    interval = tick;
    clock_gettime(CLOCK_MONOTONIC, &start_time);
}

int timerTimeOver() {
    struct timespec current_time;
    clock_gettime(CLOCK_MONOTONIC, &current_time);
    long elapsed = (current_time.tv_sec - start_time.tv_sec) * 1000 +
                   (current_time.tv_nsec - start_time.tv_nsec) / 1000000;
    return elapsed >= interval;
}

void timerDestroy() {

}
