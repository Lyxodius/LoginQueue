#include <cstdio>
#include <cmath>

int main() {
    printf("This World is currently full.\n");
    int freshQueue = 7400;
    int queue = freshQueue;
    int minutesElapsed = 0;
    int hour = 18;
    int minute = 0;
    int playersLoggingInPerMinute;
    int playersLeavingPerMinute;
    double power = 0;
    while (freshQueue > 0) {
        printf("[%.2d:%.2d] Players in queue: %d. Fresh queue: %d.\n", hour, minute, queue, freshQueue);
        minutesElapsed++;
        minute++;
        if (minute == 60) {
            hour++;
            minute = 0;
            if (hour == 24) {
                hour = 0;
            }
        }
        power = pow(2, (double) minutesElapsed / 240.0);
        playersLeavingPerMinute = (int) round((16 * power));
        playersLoggingInPerMinute = (int) round((32 * (1 / power)));
        queue -= playersLeavingPerMinute;
        if (queue < 0) queue = 0;
        freshQueue += playersLoggingInPerMinute - playersLeavingPerMinute;
        if (freshQueue < 0) freshQueue = 0;
    }
    printf("[%.2d:%.2d] Players in queue: %d\n", hour, minute, queue);
    printf("Login took %d hours and %d minutes.\n", minutesElapsed / 60, minutesElapsed % 60);
    printf("Fresh queue at this point: %d\n", freshQueue);
    return 0;
}
