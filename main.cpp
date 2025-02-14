#include <stdio.h>
#include <math.h>

int isPrime(unsigned int n) {
    // 0 and 1 are not prime numbers
    if (n <= 1) {
        return 0;
    }

    // Check divisibility up to square root of n
    // We only need to check up to sqrt(n) because if n is divisible by a number greater than its
    // square root, it would also be divisible by a number less than its square root
    // (i.e., if n = a*b, and a > sqrt(n), then b < sqrt(n))
    for (unsigned int d = 2; d <= sqrt(n); d++) {
        if (n % d == 0) {
            return 0;  // n is divisible by d, so it's not prime
        }
    }

    return 1;  // n is prime if no divisors were found
}

void isPrimeTest() {
    unsigned int n;

    while (1) {
        printf("Please enter a positive integer: ");
        scanf("%u", &n);

        // Exit condition
        if (n == 0) {
            printf("Press ENTER to exit...");
            getchar();  // Consume the newline from previous scanf
            getchar();  // Wait for ENTER
            break;
        }

        if (isPrime(n)) {
            printf("%u is a prime number!\n", n);
        } else {
            printf("%u is not a prime number.\n", n);
        }
    }
}
/*
Flowchart for isPrime function:

[Start]
     ↓
[Input n]
     ↓
[Check if n ≤ 1] → Yes → [Return 0 (Not Prime)]
     ↓ No
[Set d = 2]
     ↓
[Check if d ≤ sqrt(n)] → No → [Return 1 (Prime)]
     ↓ Yes
[Check if n is divisible by d] → Yes → [Return 0 (Not Prime)]
     ↓ No
[Increment d]
     ↑_______________|

Flowchart for isPrimeTest function:

[Start]
     ↓
[Prompt for input]
     ↓
[Get number n]
     ↓
[Check if n = 0] → Yes → [Wait for ENTER] → [End]
     ↓ No
[Call isPrime(n)]
     ↓
[Display result]
     ↑_________|
*/

unsigned int countPrimes(const unsigned int n1, const unsigned int n2, const unsigned char display) {
    unsigned int start = (n1 < n2) ? n1 : n2;
    unsigned int end = (n1 < n2) ? n2 : n1;
    unsigned int total = 0;

    for (unsigned int i = start; i <= end; i++) {
        if (isPrime(i)) {
            total++;
            if (display == 'y' || display == 'Y') {
                printf("%u\n", i);
            }
        }
    }

    return total;
}

void countPrimesTest(void) {
    unsigned int n1, n2;
    char display;

    while (1) {
        printf("Please enter n1, n2: ");
        scanf("%u,%u", &n1, &n2);

        // Exit condition
        if (n1 == 0 || n2 == 0) {
            printf("Press ENTER to exit...");
            getchar();  // Consume the newline from previous scanf
            getchar();  // Wait for ENTER
            break;
        }

        printf("Display the results? (y/n) ");
        getchar();  // Consume the newline from previous scanf
        scanf_s("%c", &display,1);

        unsigned int total = countPrimes(n1, n2, display);
        printf("%u total primes found between %u and %u.\n", total, n1, n2);
    }
}

/*
Flowchart for countPrimes function:

[Start]
     ↓
[Input n1, n2, display]
     ↓
[Set start = min(n1,n2)]
[Set end = max(n1,n2)]
[Set total = 0]
     ↓
[Check if i ≤ end] → No → [Return total]
     ↓ Yes
[Call isPrime(i)]
     ↓
[If prime] → Yes → [Increment total]
     ↓           → [If display, print number]
[Increment i]
     ↑_______________|

Flowchart for countPrimesTest function:

[Start]
     ↓
[Prompt for n1, n2]
     ↓
[Get numbers]
     ↓
[Check if either = 0] → Yes → [Wait for ENTER] → [End]
     ↓ No
[Prompt for display option]
     ↓
[Call countPrimes]
     ↓
[Display total]
     ↑_________|
*/


int main() {
    countPrimesTest();
}