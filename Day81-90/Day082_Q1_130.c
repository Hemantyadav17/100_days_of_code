#include <stdio.h>
#include <string.h>

enum TrafficLight {
    RED = 0,
    YELLOW = 1,
    GREEN = 2
};

int main() {
    char light_input[20];
    enum TrafficLight light;
    
    printf("Enter traffic light color (RED, YELLOW, or GREEN): ");
    scanf("%s", light_input);
    
    for (int i = 0; light_input[i]; i++) {
        if (light_input[i] >= 'a' && light_input[i] <= 'z') {
            light_input[i] = light_input[i] - 32;
        }
    }

    if (strcmp(light_input, "RED") == 0) {
        light = RED;
    } else if (strcmp(light_input, "YELLOW") == 0) {
        light = YELLOW;
    } else if (strcmp(light_input, "GREEN") == 0) {
        light = GREEN;
    } else {
        printf("Invalid traffic light color!\n");
        return 1;
    }
    
    switch (light) {
        case RED:
            printf("Stop\n");
            break;
        case YELLOW:
            printf("Wait\n");
            break;
        case GREEN:
            printf("Go\n");
            break;
        default:
            printf("Invalid light\n");
    }
    
    return 0;
}