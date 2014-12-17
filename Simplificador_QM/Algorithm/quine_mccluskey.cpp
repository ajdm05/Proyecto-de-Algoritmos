#include "Algorithm/quine_mccluskey.h"

vector< vector<int> > canonicalFunctions;
vector< vector<int> > usedFunctions;
int numbersOfVariables;
int numbersOfFunctions;
using namespace std;
Quine_McCluskey::Quine_McCluskey(vector< vector<int> > myCanonicalFunctions,  int functionsAmount, int variablesAmout)
{
    canonicalFunctions = myCanonicalFunctions;
    numbersOfFunctions = functionsAmount;
    numbersOfVariables = variablesAmout;
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
    int lastSum=0;

    for(int row=0; row<getNumbersOfFunctions(); row++)
    {
        int rowSum=0;
        vector<int> vectorRow = canonicalFunctions.at(row);
        for(int column=0; column<getNumbersOfVariables(); column++)
        {
            rowSum += vectorRow.at(column);
            if(rowSum > lastSum)
            {
                lastSum = rowSum;
                groups++;
            }
        }
    }
    return groups;
}

vector< vector<int> > Quine_McCluskey::campareEachElementWithElementInBlock()
{
    int strikes = 0;
    vector< vector<int> > posibleAnswer;
    vector< vector<int> > usedFunctionsInFirstGroup;
    vector< vector<int> > usedFunctionsInSecondGroup;

    int groups = getHowManyGroupsAreInTheCanonicalArray();

    for(int group=1; group<=groups; group++)
    {
        vector< vector<int> > firstGettedGroup = getGroup(group);
        vector< vector<int> >  secondGettedGroup;
        if((group+1) <= groups)
            secondGettedGroup = getGroup(group+1);
        else
            return posibleAnswer;
        for(int first=0; first< firstGettedGroup.size(); first++)
        {
            vector<int> elementOfFirsGroup = firstGettedGroup.at(first);

            for(int second=0; second<secondGettedGroup.size(); second++)
            {
                vector<int> elementOfSecondGroup = secondGettedGroup.at(second);
                vector<int> temporalAnswer;
                for(int column=0; column<getNumbersOfVariables(); column++)
                {
                    if(strikes > 1)
                    {
                        temporalAnswer.clear();
                        strikes =0;
                        break;
                    }

                    if(elementOfFirsGroup.at(column) == elementOfSecondGroup.at(column))
                        temporalAnswer.push_back(elementOfFirsGroup.at(column));

                    if(elementOfFirsGroup.at(column) != elementOfSecondGroup.at(column))
                    {
                        temporalAnswer.push_back(-1);
                        strikes++;
                    }

                    if(strikes <= 1 && (column+1)==getNumbersOfVariables())
                    {
                        strikes =0;
                        posibleAnswer.push_back(temporalAnswer);
                        //usedFunctionsInSecondGroup(temporalAnswer);
                        if(!verifyIfFunctionExistInUsedFunctions(temporalAnswer))
                            setUsedFunctions(temporalAnswer);
                    }
                }
            }
            if(usedFunctionsInSecondGroup.size() > 0 && !verifyIfFunctionExistInUsedFunctions(elementOfFirsGroup))
                setUsedFunctions(elementOfFirsGroup);
        }
    }
    return posibleAnswer;
}

vector< vector<int> > Quine_McCluskey::getGroup(int number)
{
    vector< vector<int> > group;

    for(int row=0; row<getNumbersOfFunctions(); row++)
    {
        int rowSum=0;
        vector<int> vectorRow = canonicalFunctions.at(row);
        for(int column=0; column<getNumbersOfVariables(); column++)
        {
            rowSum += vectorRow.at(column);
            if(rowSum == number && (column+1) == getNumbersOfVariables())
                group.push_back(vectorRow);

            if(rowSum > number)
            {
                row = getNumbersOfFunctions();
                break;
            }
        }
    }
    return group;
}

vector< vector<int> > Quine_McCluskey::getCanonicalFunctions()
{
    return canonicalFunctions;
}

void Quine_McCluskey::setUsedFunctions(vector<int> functions)
{
    usedFunctions.push_back(functions);
}

vector< vector<int> > Quine_McCluskey::getUsedFunctions()
{
    return usedFunctions;
}

bool Quine_McCluskey::verifyIfFunctionExistInUsedFunctions(vector<int> function)
{

    for(int position=0; position<getUsedFunctions().size(); position++)
    {
        int verify = 0;
        vector<int> temp = getUsedFunctions().at(position);
        for(int pos=0; pos < getNumbersOfVariables(); pos++)
        {
            if(temp.at(pos) == function.at(pos))
                verify++;

            if(verify==getNumbersOfVariables())
                return true;
        }
    }
    return false;
}

int Quine_McCluskey::verifyHowManyUsedFunctionsOfGroupExistInUsedFunctions(vector< vector<int> > functions, int group)
{
    vector< vector<int> > temporaryFunctions = getGroup(group);
    if(temporaryFunctions.size() == functions.size())
        return functions.size();

    int amountOfFunctions =0;
    for(int pos=0; pos <functions.size(); pos++)
    {
        if(verifyIfFunctionExistInUsedFunctions(functions.at(pos)))
            amountOfFunctions++;
    }
    return amountOfFunctions;
}

