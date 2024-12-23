#ifndef UTILITY_H
#define UTILITY_H

#define MAX_TURNS 6
#define WORD_SIZE 5
#define DEFAULT_CHARACTER "*"

#define ESC "\033["
#define COLOR_DEFAULT "6m"
#define COLOR_INCORRECT_SPOT "33m"
#define COLOR_CORRECT_SPOT "32m"
#define COLOR_RESET "\033[m"

// #define DATA_FILE "" 

#include <vector>
#include <string>

std::vector<std::string> LoadWords(std::string fileName);
std::string SelectWord(std::vector<std::string> wordList);

#endif // UTILITY_H
