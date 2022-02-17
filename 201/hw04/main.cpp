//Oðuz Kuyucu 21902683
#include "AlgebraicExpression.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
int main(){
    //string str = "( ( ( 11 + 22 ) * 3 + 1 ) * 10 ) / 10";
    string str = "( 11 - 22 ) * ( ( 33 + 44 ) / 55 )";
    string k = "13 - 14 * 5";
    string a;
    string b;
    string c;
    double res;
    //either this or below one may be tested
    //a = infix2postfix(str)
    a = infix2postfix(k);
    cout<<infix2prefix("( 11 - 22 ) * ( ( 33 + 44 ) / 55 )")<<endl;
    b = postfix2prefix(a);
    cout<<postfix2infix(a)<<endl;
    c = prefix2infix(b);
    cout<<prefix2postfix(b)<<endl;
    //a = infix2postfix(c);
    //b = postfix2prefix(a);
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
    std::cout<<c<<std::endl;
    string strin = "012345";
    res = evaluatePostfix(a);
    std::cout<<evaluateInfix(c)<<endl;
    std::cout<<evaluatePrefix(b)<<endl;
    std::cout<<res<<endl;

    cout << infix2prefix("( 12 + 5 ) - 20 * 4") << endl;
    cout << infix2postfix("( 12 + 5 ) - 20 * 4") << endl;
    cout << evaluateInfix("( 12 + 5 ) - 20 * 4") << endl;
    cout << prefix2infix("* + * 100 2 4 - 12 4") << endl;
    cout << prefix2postfix("* + * 100 2 4 - 12 4") << endl;
    cout << evaluatePrefix("* + * 100 2 4 - 12 4") << endl;
    cout << postfix2infix("100 12 2 - 8 * + 4 /") << endl;
    cout << postfix2prefix("100 12 2 - 8 * + 4 /") << endl;
    cout << evaluatePostfix("100 12 2 - 8 * + 4 /") << endl;

}
