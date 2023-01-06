#include <stdio.h>

int main() {
    int candidate = 5; /* test odd numbers only, obviously */
    int prime[1000];
    
    int index = 1; /* current max index of prime[] */
    int ok; /* index of candidate */
    prime[0] = 2;
    prime[1] = 3;

    int i;
    for (;;) {
        ok = 0; /* initialization from 0 */
        for (i = 0; i <= index; i++) {
            if (candidate % prime[i] != 0) {
                ok++;
            }
            else {
                break;
            }
        }

        if (ok == index + 1) {
            prime[ok] = candidate;
            index++;
            printf("New Prime: %d\n", candidate);
            if (index == 999) {
                break;
            }
        }

        candidate += 2; /* next candidate */
    }
    return 0;
}