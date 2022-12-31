/*********************************************************************
* Password Checker                                                   *
*********************************************************************/
#include <iostream>
#include <string>

void printStrongness(std::string& input) {
   int n = input.length();
   bool hasLower = false, hasUpper = false;
   bool hasDigit = false, specialChar = false;

   std::string normalChars = "abcdefghijklmnopqrstu" "vwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
   for (int i = 0; i < n; i++) {
      if (islower(input[i]))
         hasLower = true;
      if (isupper(input[i]))
         hasUpper = true;
      if (isdigit(input[i]))
         hasDigit = true;
      size_t special = input.find_first_not_of(normalChars);
      if (special != std::string::npos)
         specialChar = true;
   }

   std::cout << "Strength of password:-";
   if (hasLower && hasUpper && hasDigit &&
      specialChar && (n >= 8))
      std::cout << "Strong" << std::endl;
   else if ((hasLower || hasUpper) &&
      specialChar && (n >= 6))
      std::cout << "Moderate" << std::endl;
   else
      std::cout << "Weak" << std::endl;
}
int main() {
   std::string input;
   std::cout << "Input Password Here: ";
   std::cin >> input;
   printStrongness(input);
   return 0;
}