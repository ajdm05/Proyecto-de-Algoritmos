#ifndef QUINE_MCCLUSKEY_H
#define QUINE_MCCLUSKEY_H
#include <vector>
#include "iostream"

using namespace std;
class Quine_McCluskey
{
public:
    Quine_McCluskey(vector< vector<int> > myCanonicalFunctions, int functionsAmount, int variablesAmout);
    int getNumbersOfVariables();
    int getNumbersOfFunctions();
    vector< vector<int> > getCanonicalFunctions();
    vector< vector<int> > campareEachElementWithElementInBlock();
    int getHowManyGroupsAreInTheCanonicalArray();
    int getThePositionWhereAnyGroupBeging(int groupNumber);
    int getHowManyFunctionsPerGroupAre(int groupNumber);
    vector< vector<int> > getGroup(int number);
    void setUsedFunctions(vector<int> function);
    vector< vector<int> > getUsedFunctions();
    bool verifyIfFunctionExistInUsedFunctions(vector<int> function);
    int verifyHowManyUsedFunctionsOfGroupExistInUsedFunctions(vector< vector<int> > functions, int group);
};

#endif // QUINE_MCCLUSKEY_H
