/*
#include "Windows/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
*/
#include "Expression/expression.h"
#include "Parsing/Parser.h"

using namespace std;

void printNode(Node *n){
    if(n->getType() == AndNodeType){
        cout << "(";
        printNode(((AndNode*)n)->getIzqNode());
        cout << ")&(";
        printNode(((AndNode*)n)->getDerNode());
        cout << ")";
    }else if(n->getType() == OrNodeType){
        cout << "(";
        printNode(((OrNode*)n)->getIzqNode());
        cout << ")|(";
        printNode(((OrNode*)n)->getDerNode());
        cout << ")";
    }else if(n->getType() == NotNodeType){
        cout << "~(";
        printNode(((NotNode*)n)->getNode());
        cout << ")";
    }else if(n->getType() == IdNodeType){
        cout << ((IdNode*)n)->getId();
    }
}

/*
 *
 */
int main(int argc, char** argv) {
    char * input = "a|d|b&c";

    Parser p(input);
    Node *n = p.Parse();
    cout << "Parsed Expression:\n";
    printNode(n);

    cout << "Given a=true, d=false, b=true, c=true";
    cout << "The expression evaluates to: ";
    map<string, bool> values;
    values["a"] = false;
    values["d"] = false;
    values["b"] = true;
    values["c"] = false;

    Expression expre(n);

    cout << expre.evaluateExpression(&values);


    return 0;
}
