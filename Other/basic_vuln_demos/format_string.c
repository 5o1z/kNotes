#include <stdio.h>
#include <string.h>

/*
 * Format String in C - Concept and Vulnerability Demo
 *
 * -------------------------------------
 * Format specifiers commonly used with printf:
 * -------------------------------------
 *   %d / %i   : signed decimal integer
 *   %u        : unsigned decimal integer
 *   %x / %X   : unsigned hexadecimal (lower / upper case)
 *   %o        : unsigned octal
 *   %c        : character
 *   %s        : string (pointer to char array)
 *   %p        : pointer address
 *   %f        : floating point number
 *   %n        : write the number of characters printed so far into a variable
 *
 * -------------------------------------
 * Format String Vulnerability Overview:
 * -------------------------------------
 * - A format string vulnerability occurs when user input is passed directly
 *   as the format string to functions like printf(), fprintf(), etc.
 *
 * - If user-controlled input contains format specifiers (e.g., %x, %s, %n),
 *   they are interpreted by the format function, leading to:
 *     - Information disclosure (memory leaks)
 *     - Arbitrary memory write (with %n)
 *     - Program crash (denial of service)
 *
 * - This vulnerability is common in CTF binary exploitation challenges.
*/

void safe_usage(const char *user_input)
{
    // User input is printed using a fixed format string (%s)
    printf("[Safe] Your input was: %s\n", user_input);
}

void unsafe_usage(const char *user_input)
{
    // User input is passed directly as the format string (vulnerable)
    // If the input contains format specifiers, they will be processed
    printf("[Unsafe] Interpreting your input as format string:\n");
    printf(user_input); // VULNERABLE: user_input is treated as format string
    printf("\n");
}

int main()
{
    char user_input[256];

    printf("Enter your input: ");
    fgets(user_input, sizeof(user_input), stdin);
    user_input[strcspn(user_input, "\n")] = '\0'; // remove newline

    // Demonstrate safe usage
    safe_usage(user_input);

    // Demonstrate unsafe usage (vulnerable to format string attack)
    unsafe_usage(user_input);

    return 0;
}
