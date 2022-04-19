#include <stdio.h>
#include <string.h>

int main() {
    struct state {
        int population;
        char description[30];
    };

    struct state names[3] = { { 12807060, "PA"}, { 8908520, "NJ"}, {19542209, "NY"} };
    printf("%d %s", names[2].population, (*(names+2)).description);
}
