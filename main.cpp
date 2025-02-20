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
unsigned int primeFactorization(const unsigned int n1, const unsigned int n2, const unsigned int nFactors, const unsigned char display) {
    unsigned int start = (n1 < n2) ? n1 : n2;
    unsigned int end = (n1 > n2) ? n1 : n2;
    unsigned int total = 0;

    // Skip 1 since it has no prime factors
    if (start < 2) start = 2;

    for (unsigned int i = start; i <= end; i++) {
        unsigned int num = i;
        unsigned int factorCount = 0;

        // Count prime factors
        for (unsigned int j = 2; j <= num; j++) {
            if (!isPrime(j)) continue;

            while (num % j == 0) {
                factorCount++;
                num /= j;
            }
        }

        if (factorCount == nFactors) {
            total++;
            if (display == 'y' || display == 'Y') {
                num = i;
                printf("%u |", i);
                // Print prime factors
                for (unsigned int j = 2; j <= num; j++) {
                    if (!isPrime(j)) continue;
                    while (num % j == 0) {
                        printf(" %u |", j);
                        num /= j;
                    }
                }
                printf("\n");
            }
        }
    }
    return total;
}

void primeFactorizationTest() {
    unsigned int n1, n2, nFactors;
    unsigned char display;

    while (1) {
        printf("Please enter n1, n2: ");
        scanf_s("%u,%u", &n1, &n2);

        if (n1 == 0 || n2 == 0) {
            printf("Press ENTER to exit...");
            getchar();  // Consume newline
            getchar();  // Wait for ENTER
            break;
        }

        printf("Please enter the number of prime factors to find: ");
        scanf_s("%u", &nFactors);

        printf("Display the results? (y/n) ");
        getchar();  // Consume the newline from previous scanf
        scanf_s("%c", &display, 1);

        unsigned int total = primeFactorization(n1, n2, nFactors, display);
        printf("%u total numbers with %u prime factors found between %u and %u.\n",
               total, nFactors, n1, n2);
    }
}

/*
Flowchart for primeFactorization function:

[Start]
     ↓
[Input n1, n2, nFactors, display]
     ↓
[Set start = min(n1,n2)]
[Set end = max(n1,n2)]
[Set total = 0]
     ↓
[Check if i ≤ end] → No → [Return total]
     ↓ Yes
[Set num = i, factorCount = 0]
     ↓
[For each potential prime j]
     ↓
[If j is prime]
     ↓
[While num divisible by j]
     ↓
[Increment factorCount]
[Divide num by j]
     ↓
[If factorCount equals nFactors]
     ↓
[Increment total]
[If display, print number and factors]
     ↓
[Increment i]
     ↑_______________|
*/


enum mainMenu {EXIT, TASK1, TASK2, TASK3};

int main() {
    int choice;
    
    do {
        printf("\nPrime Number Operations Menu:\n");
        printf("%d. Test if a number is prime\n", TASK1);
        printf("%d. Count prime numbers in a range\n", TASK2);
        printf("%d. Prime factorization\n", TASK3);
        printf("%d. Exit\n", EXIT);
        printf("Enter your choice (%d-%d): ", EXIT, TASK3);
        
        if (scanf_s("%d", &choice) != 1) {
            // Clear input buffer if invalid input
            while (getchar() != '\n');
            choice = -1;  // Invalid choice
        }
        
        switch (choice) {
            case TASK1:
                isPrimeTest();
                break;
            case TASK2:
                countPrimesTest();
                break;
            case TASK3:
                primeFactorizationTest();
                break;
            case EXIT:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != EXIT);
    
    return 0;
}