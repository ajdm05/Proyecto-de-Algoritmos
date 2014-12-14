#ifndef BOOLEANEXPRESSION_H
#define BOOLEANEXPRESSION_H
#include <string>

using namespace std;

enum EvaluationType {SUCCESS, FAIL};

class Expression{
public:
    virtual bool evaluate() = 0;
    EvaluationType Result;
};

class Operator: public Expression{

};

class Operand: public Expression{

};

class Constant: public Operand{
private:
    bool _value;
public:
    Constant(bool val){ setValue(val); }

    bool value()const {return _value;}
    void setValue(bool const newValue){
        _value = newValue;
    }

};

class Variable: public Operand{
private:
    string _name;
public:
    ///Constructor
    Variable(string name){ setValue(name); }

    string name()const{ return _name; }
    void setValue(const string newName){
        _name = newName;
    }
};

class UnaryOperator: public Operator{
private:
    Expression* _childExpression;
public:
    void setChildExpression(Expression* expression){
        _childExpression = expression;
    }
    Expression* childExpression(){ return _childExpression; }
};

class BinaryOperator: public Operator{
private:
    Expression* _leftExpression;
    Expression* _rightExpression;
public:
    void setLeftChildExpression(Expression* expression){
        _leftExpression = expression;
    }
    void setRightChildExpression(Expression* expression){
        _rightExpression = expression;
    }
    Expression* leftExpression(){ return _leftExpression; }
    Expression* rightExpression(){ return _rightExpression; }
};

class NotOperator: public UnaryOperator{
public:
    virtual bool evaluate(){
        if(childExpression() == NULL) Result = FAIL;
        Result = SUCCESS;
        return !childExpression();
    }
};

#endif // BOOLEANEXPRESSION_H
