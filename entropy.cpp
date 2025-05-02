#include <iostream>
#include <cmath>
#include <string>

int compute(std::string input) {
    bool hasLower{ false };
    bool hasDigits{ false };
    bool hasUpper{ false };
    bool hasSymbols{ false };
    int poolSize{ 0 };

    for (int i{ 0 }; i < input.length(); i++) {
        if (input[i] >= 'a' && input[i] <= 'z') hasLower = true;
        else if (input[i] >= 'A' && input[i] <= 'Z') hasUpper = true;
        else if (input[i] >= '0' && input[i] <= '9') hasDigits = true;
        else hasSymbols = true;
    }

    if (hasLower) poolSize += 26; // 26 lower cases
    if (hasUpper) poolSize += 26; // 26 upper cases
    if (hasDigits) poolSize += 10; // 10 digits
    if (hasSymbols) poolSize += 33; // 33 symbols

    float entropy = input.length() * (log(poolSize) / log(2));
    return entropy;
}


int main()
{
    std::string input;
    while (true) {
        std::cout << "Enter password to check entropy: ";
        std::getline(std::cin, input);

        if (input.empty()) {
            std::cout << "Password cannot be empty, please try again!\n";
            continue;
        }

        float entropy = compute(input);
        if (entropy <= 30) std::cout << "Password entropy too low. Choose a longer or more complex password.\n";
        else {
            std::cout << "Entropy is: " << entropy;
            break;
        }

    }

}

