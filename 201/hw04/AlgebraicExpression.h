//Oðuz Kuyucu 21902683
#include <string>
#include <iostream>
#ifndef ALGEBRAICEXPRESSION_H
#define ALGEBRAICEXPRESSION_H
using namespace std;
string infix2prefix( const string exp );
         //It converts an infix expression exp to its equivalent postfix form.
string infix2postfix( const string exp );
        // It converts a prefix expression exp to its equivalent infix form.
string prefix2infix( const string exp );
        // It converts a prefix expression exp to its equivalent postfix form.
string prefix2postfix( const string exp );
        // It converts a postfix expression exp to its equivalent infix form.
string postfix2infix( const string exp );
        // It converts a postfix expression exp to its equivalent prefix form.
string postfix2prefix( const string exp );
        //It evaluates an infix expression.
double evaluateInfix( const string exp );
        //It evaluates a prefix expression.
double evaluatePrefix( const string exp );
        //It evaluates a postfix expression.
double evaluatePostfix( const string exp );
class AlgebraicExpression
{
        //It converts an infix expression exp to its equivalent prefix form.

    public:

    protected:

    private:
};

#endif // ALGEBRAICEXPRESSION_H
