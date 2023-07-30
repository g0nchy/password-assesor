# Password Assessor

[![GitHub License](https://github.com/g0nchy/password-assessor/)

This is a simple command-line password assessor program written in C. I developed it while doing the CS50x course, which is Harvard's Introduction to Computer Science from HarvardX. The program evaluates the strength of a user-provided password based on various criteria such as length, the presence of uppercase and lowercase letters, numbers, and special characters.

## Features

- The program uses an enumeration to represent different password strengths: WEAK, POOR, GOOD, EXCELLENT, and UNKNOWN.
- Password length is validated to be within a specific range (0 to 18 characters).
- The program calculates the number of uppercase letters, lowercase letters, numbers, and special characters in the password.
- Based on the counts, the program determines the password strength and displays the result accordingly.
- It provides informative messages indicating the time a cracker would take to crack the password for each strength category.

## How to Use

1. Clone the repository to your local machine.
2. Compile the `password-assessor.c` file using a C compiler.
3. Run the compiled executable.
4. Enter the password when prompted.
5. The program will evaluate the password strength and display the result.

**Note:** The password strength criteria can be adjusted by modifying the constants (e.g., WEAK_PASSWORD_THRESHOLD, POOR_PASSWORD_THRESHOLD, etc.) in the code.

## Dependencies

This project uses the CS50 library to handle user input. To compile and run the program, you'll need to have the CS50 library installed on your system.

You can download and install the CS50 library from the official website: https://cs50.readthedocs.io/libraries/cs50/c/

## Data Source

The estimated times to crack passwords mentioned in this program are based on data from a study conducted by Hive Systems. The study used MD5 hashed passwords cracked by an RTX 2080 GPU. You can find more information about the study and the data on their blog post [here](https://www.hivesystems.io/blog/are-your-passwords-in-the-green).

## License

This code is open-source and available under the [MIT License](https://opensource.org/licenses/MIT). You are free to use, modify, and distribute the code as per the terms of the license.

## Contributions

Contributions are welcome! If you find any issues or have suggestions for improvements, feel free to open an issue or submit a pull request.

## Acknowledgments

Special thanks to the CS50 Library for providing the `cs50.h` header used in this project.

