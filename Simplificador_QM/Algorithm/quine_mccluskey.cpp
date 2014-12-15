#include "quine_mccluskey.h"

#define TRUE 1
#define FALSE 0
#define MAXVARS 7
#define MAX 2048

int canocicalFunctions[][];
int numbersOfVariables;
int numbersOfFunctions;

Quine_McCluskey::Quine_McCluskey(int myCanonicalFunctions[][], int variablesAmout, int functionsAmount)
{
    canocicalFunctions = myCanonicalFunctions;
    numbersOfVariables = variablesAmout;
    numbersOfFunctions = functionsAmount;
}

int Quine_McCluskey::getNumbersOfVariables()
{
    return numbersOfVariables;
}

int Quine_McCluskey::getNumbersOfFunctions()
{
    return numbersOfFunctions;
}

canocicalArray Quine_McCluskey::getCanonicalArray()
{
    return canocicalFunctions;
}

void Quine_McCluskey::campareEachElementWithElementInBlock()
{
    int strikes = 0;
}
