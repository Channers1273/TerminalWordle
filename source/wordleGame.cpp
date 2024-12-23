#include "wordleGame.h"
#include "utility.h"
#include <stdlib.h>
#include <stdio.h> 
#include <string.h> 
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <cstring>

WordleGameManager::WordleGameManager(std::string fileName)
{
  dataFile = fileName;
  GenerateTarget();
  turnsLeft = MAX_TURNS;
  nextFreeRow = 0;
  gameWon = false;

  for (int i = 0; i < MAX_TURNS; i++)
  {
    for (int j = 0; j < WORD_SIZE; j++)
    {
      Letter character;
      gameBoard[i][j] = character; 
    }
  }
}

void WordleGameManager::GenerateTarget()
{ 
  std::vector<std::string> wordsList = LoadWords(dataFile);
  target = SelectWord(wordsList);
}

int WordleGameManager::GetTurnsLeft()
{
  return turnsLeft;
}

void WordleGameManager::DisplayGameGrid()
{
  for (int i = 0; i < MAX_TURNS; i++)
  {
    std::cout << "[ ";

    for (int j = 0; j < WORD_SIZE; j++) 
    {
      gameBoard[i][j].PrintLetter();
    }
    std::cout <<"]\n";
  }
}

std::string WordleGameManager::TakeInput()
{
  std::string input;
  std::cout << "> ";
  std::cin >> input;

  while (input.length() != WORD_SIZE)
  {
    std::cout<< "Please enter a word that is " << WORD_SIZE << " letters long.\n";
    std::cout << "> ";
    std::cin >> input;
  }

  return input;
}

void WordleGameManager::PlaceInGrid(std::string guess)
{
  for (int i = 0; i < WORD_SIZE; i++)
  {
    gameBoard[nextFreeRow][i].entry = guess[i];
  }
  nextFreeRow++;
}


void WordleGameManager::CheckGuess()
{
  GeneratePool();

  int currentIndex = MAX_TURNS - GetTurnsLeft();

  int correctLetterPlacementCount = 0;

  // Check letter by letter
  for (int i = 0; i < WORD_SIZE; i++)
  {
    Letter* currentLetter = &(gameBoard[currentIndex][i]);

    for (int j = 0; j < letterPool.size(); j++)
    {
      std::string currentLetterPool = "";
      currentLetterPool += letterPool[j];

      if (currentLetter->entry == currentLetterPool) // a letter in the guess is in the pool
      {
        // change the colour of the letter
        std::string targetLetter = "";
        targetLetter += target[i];

        if (currentLetter->entry.compare(targetLetter) == 0)
        {
          currentLetter->SetColourCode(COLOR_CORRECT_SPOT);
          correctLetterPlacementCount++;
        }
        else 
        {
          currentLetter->SetColourCode(COLOR_INCORRECT_SPOT);
        }

        SwapLettersInPool(j);
        letterPool.pop_back();
        j = letterPool.size() + 1; // to break out of the loop
      }
    }
  }

  if (correctLetterPlacementCount == WORD_SIZE) WinGame();

  DecrementTurnsLeft();
}

void WordleGameManager::GeneratePool()
{
  // clear the pool
  while (!letterPool.empty()) 
  {
    letterPool.pop_back();
  }

  for (int i = 0; i < WORD_SIZE; i++)
  {
    std::string letter = "";
    letter += target[i];
    letterPool.push_back(letter);
  }
}


void WordleGameManager::SwapLettersInPool(int indexToBeRemoved)
{
  std::string buffer = letterPool.back();
  letterPool.at(letterPool.size() - 1) = letterPool[indexToBeRemoved];
  letterPool[indexToBeRemoved] = buffer;
}


void WordleGameManager::DecrementTurnsLeft()
{
  turnsLeft--;
}

void WordleGameManager::WinGame()
{
  gameWon = true;
}

bool WordleGameManager::HasWon()
{
  return gameWon;
}

std::string WordleGameManager::GetTarget()
{
  return target;
}
