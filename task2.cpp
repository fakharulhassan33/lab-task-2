#include <iostream>
#include <stdlib.h>
using namespace std;

int count = 0; // Global variable to keep track of the position in the input expression
string expr;   // Global variable to store the input expression

// Function prototypes
void E();   // Function to parse an expression
void Ed();  // Function to parse expression prime (for addition and subtraction)
void T();   // Function to parse a term
void Td();  // Function to parse term prime (for multiplication and division)
void F();   // Function to parse a factor

int main() {
  // Read the input expression from the user
  cin >> expr;
  // Calculate the length of the input expression
  int l = expr.length();
  // Append "$" to the end of the input expression to indicate the end
  expr += "$";
  // Parse the input expression starting with the expression
  E();
  // Check if the entire input expression has been parsed
  if (l == count) {
    // If the entire input expression has been parsed, print "Accepted"
    cout << "Accepted" << endl;
    // Wait for a character input
    cin.get();
  } else
    // If not, print "Rejected"
    cout << "Rejected" << endl;
  // Wait for a character input
  cin.get();
}

// Function to parse an expression
void E() {
  // Print the production rule being used
  cout << "E->TE'" << endl;
  // Wait for a character input
  cin.get();
  // Parse a term
  T();
  // Parse expression prime
  Ed();
}

// Function to parse expression prime (for addition and subtraction)
void Ed() {
  // If current character is '+'
  if (expr[count] == '+') {
    // Move to the next character
    count++;
    // Print the production rule being used
    cout << "E'->+TE'" << endl;
    // Wait for a character input
    cin.get();
    // Parse a term
    T();
    // Parse expression prime recursively
    Ed();
  } 
  // If current character is '-'
  else if (expr[count] == '-') {
    // Move to the next character
    count++;
    // Print the production rule being used
    cout << "E'->-TE'" << endl;
    // Wait for a character input
    cin.get();
    // Parse a term
    T();
    // Parse expression prime recursively
    Ed();
  } 
  // If current character is neither '+' nor '-'
  else {
    // Print the production rule being used
    cout << "E'->null" << endl;
    // Wait for a character input
    cin.get();
  }
}

// Function to parse a term
void T() {
  // Print the production rule being used
  cout << "T->FT'" << endl;
  // Wait for a character input
  cin.get();
  // Parse a factor
  F();
  // Parse term prime
  Td();
}

// Function to parse term prime (for multiplication and division)
void Td() {
  // If current character is '*'
  if (expr[count] == '*') {
    // Move to the next character
    count++;
    // Print the production rule being used
    cout << "T'->*FT'" << endl;
    // Wait for a character input
    cin.get();
    // Parse a factor
    F();
    // Parse term prime recursively
    Td();
  } 
  // If current character is '/'
  else if (expr[count] == '/') {
    // Move to the next character
    count++;
    // Print the production rule being used
    cout << "T'->/FT'" << endl;
    // Wait for a character input
    cin.get();
    // Parse a factor
    F();
    // Parse term prime recursively
    Td();
  } 
  // If current character is neither '*' nor '/'
  else {
    // Print the production rule being used
    cout << "T'->null" << endl;
    // Wait for a character input
    cin.get();
  }
}

// Function to parse a factor
void F() {
  // If current character is alphabetic
  if (isalpha(expr[count])) {
    // Move to the next character
    count++;
    // Print the production rule being used
    cout << "F->id" << endl;
    // Wait for a character input
    cin.get();
  } 
  // If current character is a digit
  else if (isdigit(expr[count])) {
    // Move to the next character
    count++;
    // Print the production rule being used
    cout << "F->digit" << endl;
    // Wait for a character input
    cin.get();
  } 
  // If current character is '('
  else if (expr[count] == '(') {
    // Move to the next character
    count++;
    // Print the production rule being used
    cout << "F->(E)" << endl;
    // Wait for a character input
    cin.get();
    // Parse expression within parentheses
    E();
    // If ')' doesn't follow '('
    if (expr[count] != ')') {
      // Print "Rejected" and exit the program
      cout << "Rejected" << endl;
      // Wait for a character input
      cin.get();
      // Exit the program
      exit(0);
    }
    // Move to the next character
    count++;
  } 
  // If none of the above cases
  else {
    // Print "Rejected" and exit the program
    cout << "Rejected" << endl;
    // Wait for a character input
    cin.get();
    // Exit the program
    exit(0);
  }
}
