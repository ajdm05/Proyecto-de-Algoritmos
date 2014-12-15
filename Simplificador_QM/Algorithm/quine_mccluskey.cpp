#include "Algorithm/quine_mccluskey.h"

#define TRUE 1
#define FALSE 0
#define MAXVARS 7
#define MAX 2048

int **canocicalFunctions;
int numbersOfVariables;
int numbersOfFunctions;

Quine_McCluskey::Quine_McCluskey(int **myCanonicalFunctions, int variablesAmout, int functionsAmount)
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

int Quine_McCluskey::getHowManyGroupsAreInTheCanonicalArray()
{
    int groups = 0;
    int max = 0;
    int lastSum=0;

    for(int row=0; row<getNumbersOfFunctions(); row++)
    {
        int rowSum=0;
        for(int column=0; column<getNumbersOfVariables(); column++)
        {
            rowSum += canocicalFunctions[row][column];


        }
    }
    return 0;
}

void Quine_McCluskey::campareEachElementWithElementInBlock()
{
    int strikes = 0;
}
