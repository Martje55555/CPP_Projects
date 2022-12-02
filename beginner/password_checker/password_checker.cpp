#include <iostream>
using namespace std;
void printStrongNess(string& input) {
   int n = input.length();
   // Checking lower alphabet in string
   bool hasLower = false, hasUpper = false;
   bool hasDigit = false, specialChar = false;
   string normalChars = "abcdefghijklmnopqrstu" "vwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
   for (int i = 0; i < n; i++) {
      if (islower(input[i]))
         hasLower = true;
      if (isupper(input[i]))
         hasUpper = true;
      if (isdigit(input[i]))
         hasDigit = true;
      size_t special = input.find_first_not_of(normalChars);
      if (special != string::npos)
         specialChar = true;
   }
   // Strength of password
   cout << "Strength of password:-";
   if (hasLower && hasUpper && hasDigit &&
      specialChar && (n >= 8))
      cout << "Strong" << endl;
   else if ((hasLower || hasUpper) &&
      specialChar && (n >= 6))
      cout << "Moderate" << endl;
   else
      cout << "Weak" << endl;
}
int main() {
   string input;
   cout << "Input Password Here: ";
   cin >> input;
   printStrongNess(input);
   return 0;
}