#include <stdio.h>
#include <limits.h>

/*
 * Demonstration: Integer Overflow in C
 *
 * This program shows what happens when a signed integer (`int`) overflows.
 * Specifically, it adds 1 to `INT_MAX` (the maximum value for a 32-bit signed integer),
 * which causes the value to wrap around to `INT_MIN`.
 *
 * Important note about right shift (>>):
 *
 * In C, when you use the right shift operator (>>) on a signed integer (e.g., `int`),
 * the behavior is *implementation-defined* if the value is negative.
 *
 * Specifically:
 * - Some compilers perform an **arithmetic right shift**, where the sign bit is extended
 *   (shifted-in bits are filled with 1s), preserving the sign.
 * - Others may use a **logical right shift**, filling the shifted-in bits with 0s.
 *
 * Example:
 *   int x = -8;  // Binary: 11111111 11111111 11111111 11111000
 *   int result = x >> 2;
 *
 *   - Arithmetic shift: 11111111 11111111 11111111 11111110 (-2)
 *   - Logical shift:    00111111 11111111 11111111 11111110 (large positive)
 *
 * To ensure consistent results, cast to `unsigned int` before shifting bits.
 *
 * Further Reading: https://stackoverflow.com/questions/7622/are-the-shift-operators-arithmetic-or-logical-in-c
 */

// Function to print the bits of an unsigned integer
void print_bits(unsigned int x)
{
    for (int i = 31; i >= 0; i--)
    {
        /*
            * Right shift the number by i bits and mask with 1 to get the bit at position i.
            * This will print the bits from most significant to least significant.
        */
        printf("%d", (x >> i) & 1);
        if (i % 4 == 0)
            printf(" ");
    }
    printf("\n");
}

int main()
{
    int a = INT_MAX; // 2147483647

    printf("Before overflow:\n");
    printf("Signed Value:   %d\n", a);
    printf("Bit:            ");
    print_bits((unsigned int)a);

    a = a + 1; // Overflow occurs here

    printf("\nAfter overflow (a + 1):\n");
    printf("Signed Value:   %d\n", a);
    printf("Bit:            ");
    print_bits((unsigned int)a);

    return 0;
}
