#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 20
#define WSIZE 50

void get_adjective(char letter, char adjective[]);
void get_subject(char month[], char subject[]);
void get_complement(int digit, char complement[]);

int main() {
    char adjective[SIZE], subject[SIZE], complement[SIZE], movieTitle[WSIZE];
    char lastName, birthMonth[4];
    int cellDigit;

    printf("*** Welcome to the Title Movie creator program ***\n");

    // Get user input for the movie title
    printf("Enter the first letter of your last name[A-Z] ");
    scanf(" %c", &lastName);

    printf("Enter your birth month [JAN|FEB|...|DEC] ");
    scanf("%s", birthMonth);

   // Convert the birth month to uppercase
int i;
for (i = 0; i < 3; i++) {
    birthMonth[i] = toupper(birthMonth[i]);
}


    printf("Enter the last digit of your cellphone [0-9] ");
    scanf("%d", &cellDigit);

    // Validate the cellphone digit
    while (cellDigit < 0 || cellDigit > 9) {
        printf("Error! %d is not valid, please enter a valid input\n", cellDigit);
        printf("Enter the last digit of your cellphone [0-9] ");
        scanf("%d", &cellDigit);
    }

    // Call functions to determine parts of the movie title
    get_adjective(lastName, adjective);
    get_subject(birthMonth, subject);
    get_complement(cellDigit, complement);

    // Build the movie title using strcat
    strcpy(movieTitle, "The ");
    strcat(movieTitle, adjective);
    strcat(movieTitle, " ");
    strcat(movieTitle, subject);
    strcat(movieTitle, "");
    strcat(movieTitle, complement);

    // Replace special characters in the movie title
{
    int i; // Declare 'i' within a block
    for (i = 0; movieTitle[i] != '\0'; i++) {
        if (movieTitle[i] < 32 || movieTitle[i] > 126) {
            // Replace non-printable or special characters with a space
            movieTitle[i] = ' ';
        }
    }
}


    // Print the readable movie title
    printf("The Movie Title for your life is:\n%s\n", movieTitle);

    // Ask if the user wants to quit
    char quit;
    printf("Do you want to quit [Y|N]? ");
    scanf(" %c", &quit);

    if (quit != 'Y' && quit != 'y') {
        // Repeat the process
        main();
    } else {
        printf("Goodbye! See you buddy\n");
    }

    return 0;
}

void get_adjective(char letter, char adjective[]) {
    // Function to determine adjective based on the first letter of the last name
    switch (toupper(letter)) {
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
            strcpy(adjective, "awesome");
            break;
        case 'F':
        case 'G':
        case 'H':
        case 'I':
        case 'J':
            strcpy(adjective, "funny");
            break;
        case 'K':
        case 'L':
        case 'M':
        case 'N':
        case 'O':
            strcpy(adjective, "dangerous");
            break;
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
        case 'T':
            strcpy(adjective, "lovely");
            break;
        case 'U':
        case 'V':
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
            strcpy(adjective, "electrifying");
            break;
        default:
            strcpy(adjective, "unknown");
    }
}

void get_subject(char month[], char subject[]) {
    // Function to determine subject based on the birth month
    if (strcmp(month, "JAN") >= 0 && strcmp(month, "MAR") <= 0) {
        strcpy(subject, "biography");
    } else if (strcmp(month, "APR") >= 0 && strcmp(month, "JUN") <= 0) {
        strcpy(subject, "revenge");
    } else if (strcmp(month, "JUL") >= 0 && strcmp(month, "SEP") <= 0) {
        strcpy(subject, "battle");
    } else if (strcmp(month, "OCT") >= 0 && strcmp(month, "DEC") <= 0) {
        strcpy(subject, "fairy tale");
    } else {
        strcpy(subject, "unknown");
    }
}

void get_complement(int digit, char complement[]) {
    // Function to determine complement based on the last digit of the cellphone
    switch (digit) {
        case 0:
        case 1:
            strcpy(complement, "of a movie star");
            break;
        case 2:
        case 3:
            strcpy(complement, "of a hero");
            break;
        case 4:
        case 5:
            strcpy(complement, "of a jedi");
            break;
        case 6:
        case 7:
            strcpy(complement, "of an ogre");
            break;
        case 8:
        case 9:
            strcpy(complement, "of a dreamer");
            break;
        default:
            strcpy(complement, "unknown");
    }
}
