#include "letter.h"
#include "utility.h"
#include <iostream>

Letter::Letter()
{
  entry = DEFAULT_CHARACTER;
  colourCode = COLOR_DEFAULT;
}

void Letter::PrintLetter()
{
  std::cout << ESC << colourCode << entry << COLOR_RESET << " ";
}

void Letter::SetColourCode(std::string code)
{
  colourCode = code;
}
