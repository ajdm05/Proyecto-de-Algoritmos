#ifndef QUINE_MCCLUSKEY_H
#define QUINE_MCCLUSKEY_H

struct canocicalArray{
    int canocialArray [][];
};
class Quine_McCluskey
{
public:
    Quine_McCluskey(int myCanonicalFunctions[][], int variablesAmout);
    canocicalArray getCanonicalArray();
    int getNumbersOfVariables();
    int getNumbersOfFunctions();
    void campareEachElementWithElementInBlock();
    int getHowManyGroupsAreInTheCanonicalArray();

};

#endif // QUINE_MCCLUSKEY_H
