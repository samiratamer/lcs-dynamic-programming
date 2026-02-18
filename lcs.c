#include <stdio.h>
#include <string.h>
// Function to find the length of the LCS of two strings using dynamic programming
int lcsLength(char* X, char* Y, int m, int n) {
int L[m+1][n+1]; // Create a table to store lengths of longest common
subsequence
// Build the LCS table in bottom-up fashion
for (int i = 0; i <= m; i++) {
for (int j = 0; j <= n; j++) {
if (i == 0 || j == 0) {
L[i][j] = 0;
} else if (X[i-1] == Y[j-1]) {
L[i][j] = L[i-1][j-1] + 1;
} else {
L[i][j] = (L[i-1][j] > L[i][j-1]) ? L[i-1][j] : L[i][j-1];
}
}
}
// L[m][n] contains the length of LCS for X[0..m-1], Y[0..n-1]
return L[m][n];
}
// Function to print the LCS of two strings
void printLCS(char* X, char* Y, int m, int n) {
int L[m+1][n+1]; // Create a table to store lengths of longest common
subsequence
// Build the LCS table in bottom-up fashion
for (int i = 0; i <= m; i++) {
for (int j = 0; j <= n; j++) {
if (i == 0 || j == 0) {
L[i][j] = 0;
} else if (X[i-1] == Y[j-1]) {
L[i][j] = L[i-1][j-1] + 1;
} else {
L[i][j] = (L[i-1][j] > L[i][j-1]) ? L[i-1][j] : L[i][j-1];
}
}
}
// Following code is used to print LCS
int length = L[m][n];
char lcs[length+1];
lcs[length] = '\0'; // Set the terminating character
// Start from the bottom-right corner and store characters in lcs[]
int i = m, j = n;
while (i > 0 && j > 0) {
// If current character in X[] and Y[] are same, then it is part of LCS
if (X[i-1] == Y[j-1]) {
lcs[length-1] = X[i-1]; // Put current character in result
i--;
j--;
length--; // Reduce length
} else if (L[i-1][j] > L[i][j-1]) {
i--; // Move direction based on maximum value
} else {
j--;
}
}
// Print the LCS
printf("LCS of %s and %s is %s\n", X, Y, lcs);
}
int main() {
char X[] = "AGGTAB";
char Y[] = "GXTXAYB";
int m = strlen(X);
int n = strlen(Y);
printf("Length of LCS is %d\n", lcsLength(X, Y, m, n));
printLCS(X, Y, m, n);
return 0;
}
// This program uses dynamic programming to find and print the longest common
subsequence (LCS) of two given strings. It features two main functions: lcsLength
and printLCS. The lcsLength function creates a table to calculate the length of the
LCS by comparing characters from the two strings in a bottom-up approach. The
printLCS function uses this table to trace and print the actual LCS. The program
demonstrates these functions with two example strings, "AGGTAB" and "GXTXAYB,"
showing both the LCS length and the sequence itself. The main function initializes
the strings, computes the LCS length, and prints the LCS, providing a clear example
of how dynamic programming can be applied to solve sequence alignment problems
efficiently.
