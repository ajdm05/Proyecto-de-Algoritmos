
#ifndef QUINE_MCCLUSKEY_H
#define QUINE_MCCLUSKEY_H

class Quine_McCluskey
{
public:
    Quine_McCluskey(int **myCanonicalFunctions, int variablesAmout, int groupsAmount);
    int getNumbersOfVariables();
    int getNumbersOfFunctions();
    void campareEachElementWithElementInBlock();
    int getHowManyGroupsAreInTheCanonicalArray();
    int getThePositionWhereAnyGroupBeging(int groupNumber);

};

#endif // QUINE_MCCLUSKEY_H
