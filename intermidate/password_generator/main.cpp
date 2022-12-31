/*********************************************************************
* Password Generator                                                 *
*********************************************************************/
#include <iostream>
#include <time.h>

const char alphaNum[] = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int length = sizeof(alphaNum)-1;

int main() {
    int n;
    std::cout << "Enter the length of password: ";
    std::cin >> n;
    // seed random number generator
    srand(time(NULL));
    std::cout<<"Generated password: ";
    for(int i = 0; i < n; i++)
        std::cout << alphaNum[rand() % length];
    std::cout << "\n";
    return 0;
}