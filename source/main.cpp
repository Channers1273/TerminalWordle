#include <iostream>
#include "wordleGame.h"
#include "utility.h"
#include <unistd.h>
#include <string>
#include <unistd.h>
#include <limits.h>

int main(int argc, char* argv[])
{
  std::string fileName;
  char cwd[PATH_MAX];

  if (getcwd(cwd, sizeof(cwd)))
  {
    std::string currentDir(cwd);
    fileName = currentDir + argv[1];
  }
  else 
  {
    return 1;
  }

  WordleGameManager GameManager(fileName);

  GameManager.DisplayGameGrid();
 
  while (GameManager.GetTurnsLeft() > 0 && !GameManager.HasWon()) 
  {
    std::string guess = GameManager.TakeInput();
    GameManager.PlaceInGrid(guess);
    GameManager.CheckGuess();

    GameManager.DisplayGameGrid();
  }

  if (GameManager.HasWon())
  {
    std::cout << "Congrats! The word was: " << GameManager.GetTarget() << std::endl;
  }
  else
  {
    std::cout << "Out of turns. The word was: " << GameManager.GetTarget() << std::endl;
  }

  return 0;
}
