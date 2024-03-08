#include <iostream>
#include <stdlib.h>
using namespace std;

// Global variables
int count = 0; // Counter to keep track of the position in the expression string
string expr;   // Input expression

// Function prototypes
void E();   // Expression
void Ed();  // Expression prime (for addition and subtraction)
void T();   // Term
void Td();  // Term prime (for multiplication and division)
void F();   // Factor

int main() {
  // Read the expression from the user
  cin >> expr;
  // Calculate the length of the expression
  int l = expr.length();
  // Append "$" to the end of the expression to indicate the end
  expr += "$";
  // Call the expression parsing function
  E();
  // Check if the entire expression has been parsed
  if (l == count) {
    cout << "Accepted" << endl; // If entire expression is parsed, accept
    cin.get(); // Wait for a character input
  } else
    cout << "Rejected" << endl; // If not, reject
  cin.get(); // Wait for a character input
}

// Parse expression E
void E() {
  cout << "E->TE'" << endl; // Output the production rule being used
  cin.get(); // Wait for a character input
  T(); // Parse term
  Ed(); // Parse expression prime
}

// Parse expression prime (for addition and subtraction)
void Ed() {
  if (expr[count] == '+') { // If current character is '+'
    count++; // Move to the next character
    cout << "E'->+TE'" << endl; // Output the production rule being used
    cin.get(); // Wait for a character input
    T(); // Parse term
    Ed(); // Parse expression prime recursively
  } else if (expr[count] == '-') { // If current character is '-'
    count++; // Move to the next character
    cout << "E'->-TE'" << endl; // Output the production rule being used
    cin.get(); // Wait for a character input
    T(); // Parse term
    Ed(); // Parse expression prime recursively
  } else {
    cout << "E'->null" << endl; // If current character is neither '+' nor '-', output null
    cin.get(); // Wait for a character input
  }
}

// Parse term
void T() {
  cout << "T->FT'" << endl; // Output the production rule being used
  cin.get(); // Wait for a character input
  F(); // Parse factor
  Td(); // Parse term prime
}

// Parse term prime (for multiplication and division)
void Td() {
  if (expr[count] == '*') { // If current character is '*'
    count++; // Move to the next character
    cout << "T'->*FT'" << endl; // Output the production rule being used
    cin.get(); // Wait for a character input
    F(); // Parse factor
    Td(); // Parse term prime recursively
  } else if (expr[count] == '/') { // If current character is '/'
    count++; // Move to the next character
    cout << "T'->/FT'" << endl; // Output the production rule being used
    cin.get(); // Wait for a character input
    F(); // Parse factor
    Td(); // Parse term prime recursively
  } else {
    cout << "T'->null" << endl; // If current character is neither '*' nor '/', output null
    cin.get(); // Wait for a character input
  }
}

// Parse factor
void F() {
  if (isalpha(expr[count])) { // If current character is alphabetic
    count++; // Move to the next character
    cout << "F->id" << endl; // Output the production rule being used
    cin.get(); // Wait for a character input
  } else if (isdigit(expr[count])) { // If current character is a digit
    count++; // Move to the next character
    cout << "F->digit" << endl; // Output the production rule being used
    cin.get(); // Wait for a character input
  } else if (expr[count] == '(') { // If current character is '('
    count++; // Move to the next character
    cout << "F->(E)" << endl; // Output the production rule being used
    cin.get(); // Wait for a character input
    E(); // Parse expression within parentheses
    if (expr[count] != ')') { // If ')' doesn't follow '('
      cout << "Rejected" << endl; // Reject the expression
      cin.get(); // Wait for a character input
      exit(0); // Exit the program
    }
    count++; // Move to the next character
  } else {
    cout << "Rejected" << endl; // If none of the above cases, reject the expression
    cin.get(); // Wait for a character input
    exit(0); // Exit the program
  }
}
