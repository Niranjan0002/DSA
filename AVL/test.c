#include <stdio.h>

int main() {
    char ch;
    printf("Enter a character: ");
    ch = getchar(); // Read a single character from the standard input

    // Consume any remaining characters in the input buffer, including the newline character
    //int c;
    //while ((c = getchar()) != '\n' && c != EOF);

    printf("You entered: %c\n", ch);
    return 0;
}