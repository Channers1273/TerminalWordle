#ifndef WORDLE_GAME_H
#define WORDLE_GAME_H

#include <string>
#include "utility.h"
#include <vector>
#include "letter.h"

class WordleGameManager
{
  public:
    WordleGameManager(std::string fileName);
    bool HasWon();
    void PlaceInGrid(std::string guess);
    void DisplayGameGrid();
    int GetTurnsLeft();
    void CheckGuess();
    std::string GetTarget();
    std::string TakeInput();

  private:  
    std::string target;
    std::string dataFile;
    std::vector<std::string> letterPool = {};
    Letter gameBoard[MAX_TURNS][WORD_SIZE];
    int turnsLeft;
    int nextFreeRow;
    bool gameWon;
    void GeneratePool();
    void SwapLettersInPool(int indexToBeRemoved);
    void WinGame();
    void GenerateTarget();
    void DecrementTurnsLeft();
};

#endif // WORDLE_GAME_H
