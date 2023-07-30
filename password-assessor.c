#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Enum representing different password strengths
enum PasswordStrength {
    WEAK,
    POOR,
    GOOD,
    EXCELLENT,
    UNKNOWN
};

// Constants for password evaluation
const int MIN_PASSWORD_LENGTH = 0;
const int MAX_PASSWORD_LENGTH = 18;
const int WEAK_PASSWORD_THRESHOLD = 5;
const int POOR_PASSWORD_THRESHOLD = 10;
const int GOOD_PASSWORD_THRESHOLD = 13;
const int EXCELLENT_PASSWORD_THRESHOLD = 16;

// Function declarations
int count_uppercase_letters(const string password);
int count_lowercase_letters(const string password);
int count_numbers(const string password);
int count_special(const string password);
enum PasswordStrength evaluate_password_strength(const string password);

int main(void)
{
    // Variables
    string password;
    int password_length;

    // Get user input for password and validate its length
    do
    {
        password = get_string("Password: ");
        password_length = strlen(password);

        if (password_length <= MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH)
        {
            printf("Please provide a password between %i and %i characters.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        }
    }
    while (password_length <= MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH);

    // Evaluate password strength
    enum PasswordStrength strength = evaluate_password_strength(password);

    // Display password strength result
    switch (strength)
    {
        case WEAK:
            printf("Your password is weak.\n");
            printf("A cracker would instantly crack it.\n");
            break;
        case POOR:
            printf("Your password is poor.\n");
            printf("A cracker would take between 2 seconds and 1 year to crack it.\n");
            break;
        case GOOD:
            printf("Your password is good.\n");
            printf("A cracker would take between 5 years and 100k years to crack it.\n");
            break;
        case EXCELLENT:
            printf("Your password is excellent.\n");
            printf("A cracker would take between 800k years and 7qd years to crack it.\n");
            break;
        default:
            printf("We don't have any information on the password that you just provided.\n");
            break;
    }

    return 0;
}

// Functions to count specific characters in the password
int count_uppercase_letters(const string password)
{
    int uppercase_letters = 0;
    for (int i = 0, len = strlen(password); i < len; i++)
    {
        if (isupper(password[i]))
        {
            uppercase_letters++;
        }
    }
    return uppercase_letters;
}

int count_lowercase_letters(const string password)
{
    int lowercase_letters = 0;
    for (int i = 0, len = strlen(password); i < len; i++)
    {
        if (islower(password[i]))
        {
            lowercase_letters++;
        }
    }
    return lowercase_letters;
}

int count_numbers(const string password)
{
    int numbers = 0;
    for (int i = 0, len = strlen(password); i < len; i++)
    {
        if (isdigit(password[i]))
        {
            numbers++;
        }
    }
    return numbers;
}

int count_special(const string password)
{
    int special = 0;
    for (int i = 0, len = strlen(password); i < len; i++)
    {
        if (ispunct(password[i]))
        {
            special++;
        }
    }
    return special;
}

// Function to evaluate password strength based on character counts
enum PasswordStrength evaluate_password_strength(const string password)
{
    int password_length = strlen(password);
    int UL = count_uppercase_letters(password);
    int LL = count_lowercase_letters(password);
    int L = UL + LL;
    int N = count_numbers(password);
    int S = count_special(password);
    int T = L + N + S;

    if ((T == N && T <= POOR_PASSWORD_THRESHOLD) || (T == LL && T <= 7) || (LL > 0 && UL > 0 && L == T && T <= 6) || (LL > 0 && UL > 0 && N > 0 && L + N == T && T <= WEAK_PASSWORD_THRESHOLD) || (LL > 0 && UL > 0 && N > 0 && S > 0 && T <= WEAK_PASSWORD_THRESHOLD))
    {
        return WEAK;
    }
    else if ((T == N && T > POOR_PASSWORD_THRESHOLD && T <= MAX_PASSWORD_LENGTH) || (T == LL && T <= GOOD_PASSWORD_THRESHOLD) || (LL > 0 && UL > 0 && L == T && T > 6 && T <= POOR_PASSWORD_THRESHOLD) || (LL > 0 && UL > 0 && N > 0 && L + N == T && T > WEAK_PASSWORD_THRESHOLD && T <= POOR_PASSWORD_THRESHOLD) || (LL > 0 && UL > 0 && N > 0 && S > 0 && T > WEAK_PASSWORD_THRESHOLD && T <= 9))
    {
        return POOR;
    }
    else if ((T == LL && T > GOOD_PASSWORD_THRESHOLD && T <= EXCELLENT_PASSWORD_THRESHOLD) || (LL > 0 && UL > 0 && L == T && T > 6 && T <= POOR_PASSWORD_THRESHOLD) || (LL > 0 && UL > 0 && N > 0 && L + N == T && T > POOR_PASSWORD_THRESHOLD && T <= GOOD_PASSWORD_THRESHOLD) || (LL > 0 && UL > 0 && N > 0 && S > 0 && T > 9 && T <= 12))
    {
        return GOOD;
    }
    else if ((T == LL && T > EXCELLENT_PASSWORD_THRESHOLD) || (LL > 0 && UL > 0 && L == T && T > GOOD_PASSWORD_THRESHOLD) || (LL > 0 && UL > 0 && N > 0 && L + N == T && T > GOOD_PASSWORD_THRESHOLD) || (LL > 0 && UL > 0 && N > 0 && S > 0 && T > 12))
    {
        return EXCELLENT;
    }
    else
    {
        return UNKNOWN;
    }
}
