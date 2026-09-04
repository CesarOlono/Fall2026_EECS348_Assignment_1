/*
 * Program Name: EECS 348 Assignment 1 - Number Guessing Game
 *
 * Description:
 *   C program that picks a secret number between 1 and 10.
 *   The user gets up to 3 tries to guess the number. After each
 *   guess, the program tells the user if their guess was too
 *   high, too low, or correct, and stops early if they win.
 *
 * Inputs:
 *   User enters guesses via the keyboard (standard input) when
 *   prompted. Input is expected to be an integer; non-numeric
 *   input is rejected and re-prompted without using an attempt.
 *
 * Output:
 *   Terminal messages guiding the user through each attempt,
 *   feedback on each guess (too high/too low/correct), and a
 *   final win or lose message.
 *
 * Collaborators: None
 *
 * Other Sources:
 *   - ChatGPT: used to generate an initial version of this program
 *   - Claude: used to generate an initial version of this program;
 *     this final version is based on Claude's output, with added
 *     input validation (see Revisions below)
 *
 * Author: Cesar Olono
 * Creation Date: 09/03/2026
 * Revision Date: [Today's date, if different from creation]
 * Revisions:
 *   - Added non-numeric input validation (rejects letters/symbols
 *     and re-prompts the user without consuming an attempt).
 *     This improves correctness (program no longer breaks or
 *     misbehaves on bad input) and only slightly affects
 *     maintainability (one added loop, clearly commented).
 */

#include <stdio.h>

int main(void)
{
    const int SECRET_NUMBER = 7;   /* Fixed secret number (1-10) */
    const int MAX_ATTEMPTS = 3;    /* User gets up to 3 tries */
    int guess;                     /* Stores the user's current guess */
    int guessedCorrectly = 0;      /* 0 = not yet correct, 1 = correct */

    printf("Guess a number between 1 and 10.\n");

    /* Loop runs at most MAX_ATTEMPTS times, but stops early (via
     * break) as soon as the user guesses correctly. */
    for (int attempt = 1; attempt <= MAX_ATTEMPTS; attempt++)
    {
        printf("Attempt %d/%d. Enter your guess: ", attempt, MAX_ATTEMPTS);

        /* scanf returns the number of items it successfully read.
         * If it returns 0, the user typed something that isn't a
         * number (e.g., a letter). We reject that input and ask
         * again, without using up one of the 3 attempts. */
        while (scanf("%d", &guess) != 1)
        {
            /* Clear the bad input out of the input buffer so we
             * don't get stuck re-reading the same invalid text. */
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;

            printf("That's not a valid number. Enter your guess: ");
        }

        if (guess == SECRET_NUMBER)
        {
            /* Correct guess: record the win and exit the loop now,
             * instead of waiting for remaining attempts. */
            printf("Correct! You win!\n");
            guessedCorrectly = 1;
            break;
        }
        else if (guess < SECRET_NUMBER)
        {
            printf("Too low! Try again.\n");
        }
        else /* guess > SECRET_NUMBER */
        {
            printf("Too high! Try again.\n");
        }
    }

    /* If the loop finished without a correct guess, the user has
     * used all attempts and loses. */
    if (!guessedCorrectly)
    {
        printf("Sorry, you lose! The correct number was %d.\n", SECRET_NUMBER);
    }

    return 0;
}
