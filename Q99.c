// Day 99 - Question 1: Car Fleet Calculation
// Determine the number of car fleets that arrive at the target.
// Steps: Pair each car's position with its speed, sort by position descending,
// compute time = (target - position) / speed, count fleets based on arrival times.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    int speed;
} Car;

int compare(const void* a, const void* b) {
    Car* c1 = (Car*)a;
    Car* c2 = (Car*)b;
    return c2->pos - c1->pos; // Sort descending by position
}

int main() {
    int target, n;
    scanf("%d %d", &target, &n);

    Car* cars = (Car*)malloc(n * sizeof(Car));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cars[i].pos, &cars[i].speed);
    }

    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double lastTime = 0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;
        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
        // If time <= lastTime, this car joins the fleet ahead
    }

    printf("%d\n", fleets);

    free(cars);
    return 0;
}
