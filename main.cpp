/*******************************************************************************
 * Program: Prime Number Analysis
 * 
 * Purpose: This program provides tools for analyzing prime numbers and their factors:
 *          - Testing individual numbers for primality
 *          - Finding and counting primes in a range
 *          - Finding numbers with specific counts of prime factors
 * 
 * Input Format:
 *   Main Menu: Enter number 0-3 to select operation
 *   Task 1: Single positive integer (0 to exit)
 *   Task 2: Two integers separated by comma (e.g., "10,20"), then y/n for display
 *   Task 3: Two integers for range, one for factor count, then y/n for display
 * 
 * Sample Usage:
 *   Task 1: Enter "17" to test if 17 is prime
 *   Task 2: Enter "1,100" to find primes between 1 and 100
 *   Task 3: Enter "1,50" then "3" to find numbers with exactly 3 prime factors
 *
 * Created by: Anthony Reimche
 *******************************************************************************/

#include <stdio.h>
#include <math.h>

/*******************************************************************************
 * Function: isPrimeTest
 * 
 * Input:
 *   - Prompts user for positive integers, one at a time
 *   - Enter 0 to exit
 * 
 * Output:
 *   - Displays whether each entered number is prime or not
 * 
 * Purpose:
 *   Interactive function that lets users test multiple numbers for primality
 *   until they choose to exit
 *******************************************************************************/
void isPrimeTest(void);

/*******************************************************************************
 * Function: countPrimesTest
 * 
 * Input:
 *   - Two integers (n1,n2) defining the range, comma-separated
 *   - Display option (y/n)
 *   - Enter 0 for either number to exit
 * 
 * Output:
 *   - If display=y: Lists all prime numbers found
 *   - Total count of prime numbers in range
 * 
 * Purpose:
 *   Interactive function that finds and optionally displays all prime numbers
 *   within a user-specified range
 *******************************************************************************/
void countPrimesTest(void);

/*******************************************************************************
 * Function: primeFactorizationTest
 * 
 * Input:
 *   - Two integers (n1,n2) defining the range, comma-separated
 *   - Number of prime factors to find
 *   - Display option (y/n)
 *   - Enter 0 for either range number to exit
 * 
 * Output:
 *   - If display=y: Shows each number and its prime factorization
 *   - Total count of numbers with specified factor count
 * 
 * Purpose:
 *   Interactive function that finds numbers with a specific count of prime
 *   factors within a range
 *******************************************************************************/
void primeFactorizationTest(void);

enum mainMenu {EXIT, TASK1, TASK2, TASK3};

/*******************************************************************************
 * Function: main
 * 
 * Input:
 *   - Menu selection (0-3) from user
 * 
 * Output:
 *   - Displays menu options
 *   - Returns 0 on successful execution
 * 
 * Purpose:
 *   Main control loop that presents menu and directs program flow based on
 *   user selection
 *******************************************************************************/
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

/*******************************************************************************
 * Function: isPrime
 * 
 * Input:
 *   - n: unsigned integer to test for primality
 * 
 * Output:
 *   - Returns 1 if n is prime
 *   - Returns 0 if n is not prime
 * 
 * Purpose:
 *   Core function that determines if a number is prime by checking for
 *   divisibility up to its square root
 *******************************************************************************/
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

/*******************************************************************************
 * Function: isPrimeTest
 * 
 * Input:
 *   - Prompts user for positive integers, one at a time
 *   - Enter 0 to exit
 * 
 * Output:
 *   - Displays whether each entered number is prime or not
 * 
 * Purpose:
 *   Interactive function that lets users test multiple numbers for primality
 *   until they choose to exit
 *******************************************************************************/
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

/*******************************************************************************
 * Function: countPrimes
 * 
 * Input:
 *   - n1, n2: unsigned integers defining the range to search
 *   - display: character 'y'/'Y' to show results, any other to hide
 * 
 * Output:
 *   - Returns total count of primes found
 *   - If display='y', prints each prime number found
 * 
 * Purpose:
 *   Core function that finds all prime numbers within a given range and
 *   optionally displays them
 *******************************************************************************/
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

/*******************************************************************************
 * Function: countPrimesTest
 * 
 * Input:
 *   - Two integers (n1,n2) defining the range, comma-separated
 *   - Display option (y/n)
 *   - Enter 0 for either number to exit
 * 
 * Output:
 *   - If display=y: Lists all prime numbers found
 *   - Total count of prime numbers in range
 * 
 * Purpose:
 *   Interactive function that finds and optionally displays all prime numbers
 *   within a user-specified range
 *******************************************************************************/
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

/*******************************************************************************
 * Function: primeFactorization
 * 
 * Input:
 *   - n1, n2: unsigned integers defining the range to search
 *   - nFactors: number of prime factors to look for
 *   - display: character 'y'/'Y' to show results, any other to hide
 * 
 * Output:
 *   - Returns count of numbers with exactly nFactors prime factors
 *   - If display='y', prints each number and its prime factorization
 * 
 * Purpose:
 *   Core function that finds all numbers in a range with a specific count
 *   of prime factors
 *******************************************************************************/
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

/*******************************************************************************
 * Function: primeFactorizationTest
 * 
 * Input:
 *   - Two integers (n1,n2) defining the range, comma-separated
 *   - Number of prime factors to find
 *   - Display option (y/n)
 *   - Enter 0 for either range number to exit
 * 
 * Output:
 *   - If display=y: Shows each number and its prime factorization
 *   - Total count of numbers with specified factor count
 * 
 * Purpose:
 *   Interactive function that finds numbers with a specific count of prime
 *   factors within a range
 *******************************************************************************/
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