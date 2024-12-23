#ifndef LETTER_H
#define LETTER_H

#include <string>

class Letter
{
  private:
    int status;

  public:
    std::string colourCode;
    Letter();
    std::string entry;
    void PrintLetter();
    void SetColourCode(std::string code);
};

#endif // LETTER_H
