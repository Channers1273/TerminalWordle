#include "utility.h"
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <cstring>
#include <ctime>

std::vector<std::string> LoadWords(std::string fileName)
{
  std::string selectedWord;
  std::vector<std::string> wordList;
  
  std::ifstream wordData(fileName.c_str());

  if (!wordData.is_open())
  {
    std::cout << "Fail from LoadWords" << std::endl;
    
    if (wordData.bad())
    {
      std::cerr << "Error opening file: " << fileName << std::endl;
    }

    if (wordData.fail())
    {
      std::cerr << "Error details: " << strerror(errno) << std::endl;
    }
    wordData.close();
    exit(EXIT_FAILURE);
  }

  while (getline(wordData, selectedWord))
  {
    wordList.emplace_back(selectedWord);
  }

  wordData.close();
  return wordList;
}

std::string SelectWord(std::vector<std::string> wordList)
{
  if (wordList.empty()) return "";

  int numWords = wordList.size();
  int seed = time(0);
  srand(seed);
  int index = rand() % (numWords);

  return wordList[index];
}
