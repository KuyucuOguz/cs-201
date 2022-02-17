//Oðuz Kuyucu 21902683
#include "AlgebraicExpression.h"
#include "Stack.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdlib>
using namespace std;
int precedence(string operato){
    if(operato == "*" || operato == "/"){
        return 2;
    }
    else if(operato ==  "+" || operato == "-"){
        return 1;
    }
    return 0;
}

string infix2prefix( const string exp ){
    string a = infix2postfix(exp);
    string b = postfix2prefix(a);
    return b;
}
// It converts an infix expression exp to its equivalent postfix form.

string infix2postfix( const string exp ){
    Stack stk;
    int i = 0;
    int k = 0;
    int positionOfspaceBefore= 0;
    string postFix = "";
    while(i < exp.length()){
        string next;
        string current;
        if(exp[i] == ' '  || i == (exp.size() - 1)){
            if(k == 0){
                next = exp.substr(positionOfspaceBefore,i);
                positionOfspaceBefore = i;
                k = k + 1;
            }
            else if( i == exp.size() - 1){
                next = exp.substr(positionOfspaceBefore + 1,i - positionOfspaceBefore);
            }
            else{
                next = exp.substr(positionOfspaceBefore + 1,i - positionOfspaceBefore - 1);
                positionOfspaceBefore = i;
            }
            //next.erase(remove(next.begin(), next.end(), ' '), next.end());
            if(next == "("){
                stk.push(next);
            }
            else if(next == ")"){
                if(!stk.isEmpty()){
                    while(stk.scanLastItem() != "("){
                        postFix = postFix + " " + stk.getLastItem();
                    }
                stk.pop();
                }
            }
            else if(next =="*" || next == "/" || next == "+" || next == "-"){
                while(!stk.isEmpty() && stk.scanLastItem() != "(" && precedence(next) <= precedence(stk.scanLastItem())){
                    postFix = postFix + " " + stk.getLastItem();
                }
                stk.push(next);
            }
            else{
                if( postFix == ""){
                    postFix = postFix + next;
                }
                else{
                    postFix = postFix + " " + next;
                }
            }
        }
        i = i + 1;
    }
    while(!stk.isEmpty()){
        postFix = postFix + " " + stk.getLastItem();
    }
    return postFix;
}
// It converts a prefix expression exp to its equivalent infix form.
string prefix2infix( const string exp ){
    Stack stk;
    int i = exp.length() - 1;
    int k = 0;
    int positionOfspaceBefore= exp.length() - 1;
    string infix = "";

    while(i >= 0){
        string next;
        string temp = "";
        string current;
        string operand1 = "";
        string operand2 = "";
        if(exp[i] == ' '  || i == 0){
            if(k == 0){
                next = exp.substr(i + 1, positionOfspaceBefore - i + 1);
                positionOfspaceBefore = i;
                k = k + 1;
            }
            else if( i == 0){
                next = exp.substr(0, positionOfspaceBefore);
            }
            else{
                next = exp.substr(i + 1,positionOfspaceBefore - i - 1);
                positionOfspaceBefore = i;
            }
            next.erase(remove(next.begin(), next.end(), ' '), next.end());
            if(next =="*" || next == "/" || next == "+" || next == "-"){
                //std::cout<<"1234";
                    if(!stk.isEmpty()){
                        operand1 = stk.getLastItem();
                    }
                    if(!stk.isEmpty()){
                        operand2 = stk.getLastItem();
                    }
                    if(infix == ""){
                        current = "( " + operand1 + " " + next + " " + operand2 + " )";
                        infix = " ";
                        stk.push(current);
                    }
                    else{
                        current = "( " + operand1 + " " + next + " " + operand2 + " )";
                        stk.push(current);
                    }
            }
            else{
                stk.push(next);
            }
            //std::cout<<"123456";
        }
        i = i - 1;
        //std::cout<<"12345";
    }
    //while(!stk.isEmpty()){
    //    infix = infix + " " + stk.getLastItem();
    //}
    //std::cout<<"123";
    string s = stk.scanLastItem();
    if(s[0] == ' '){
        return s.substr(1);
    }
    else{
        return s;
    }
    //return stk.getLastItem();
}
// It converts a prefix expression exp to its equivalent postfix form.
string prefix2postfix( const string exp ){
    string a = prefix2infix(exp);
    string b = infix2postfix(a);
    return b;
}
// It converts a postfix expression exp to its equivalent infix form.
string postfix2infix( const string exp ){
    string a = postfix2prefix(exp);
    string b = prefix2infix(a);
    return b;
}
// It converts a postfix expression exp to its equivalent prefix form.
string postfix2prefix( const string exp ){
    Stack stk;
    int i = 0;
    int k = 0;
    int positionOfspaceBefore= 0;
    string prefix = "";
    while(i < exp.length()){
        string operand1 = "";
        string operand2 = "";
        string next;
        string current;
        string temp;
        if(exp[i] == ' '  || i == (exp.size() - 1)){
            if(k == 0){
                next = exp.substr(positionOfspaceBefore,i);
                positionOfspaceBefore = i;
                k = k + 1;
            }
            else if( i == exp.size() - 1){
                next = exp.substr(positionOfspaceBefore + 1,i - positionOfspaceBefore);
            }
            else{
                next = exp.substr(positionOfspaceBefore + 1,i - positionOfspaceBefore - 1);
                positionOfspaceBefore = i;
            }
            next.erase(remove(next.begin(), next.end(), ' '), next.end());
            if(next =="*" || next == "/" || next == "+" || next == "-"){
                if(!stk.isEmpty())
                    operand1 = stk.getLastItem();
                if(!stk.isEmpty())
                    operand2 = stk.getLastItem();
                if(prefix == ""){
                    //prefix = prefix + next + " " + operand2 + " " + operand1;
                    temp = next + " " + operand2 + " " + operand1;
                    stk.push(temp);
                    prefix = " ";

                }
                else{
                    //prefix = prefix + " " + next + " " + operand2 + " " + operand1;
                    temp = next + " " + operand2 + " " + operand1;
                    stk.push(temp);

                }
            }
            else{
                stk.push(next);

            }
        }
        i = i + 1;
    }
    //while(!stk.isEmpty()){
    //    prefix = prefix + " " + stk.getLastItem();
    //}
    return stk.getLastItem();
}
//It evaluates an infix expression.
double evaluateInfix( const string exp ){
    string a = infix2postfix(exp);
    return evaluatePostfix(a);
}
//It evaluates a prefix expression.
double evaluatePrefix( const string exp ){
    string a = prefix2postfix(exp);
    return evaluatePostfix(a);
}
//It evaluates a postfix expression.
double evaluatePostfix( const string exp ){
    Stack stk;
    int i = 0;
    int k = 0;
    int positionOfspaceBefore= 0;
    string postFix = "";
    while(i < exp.length()){
        string next;
        string current;
        string operand1 ="";
        string operand2 = "";
        //double result;
        if(exp[i] == ' '  || i == (exp.size() - 1)){
            if(k == 0){
                next = exp.substr(positionOfspaceBefore,i);
                positionOfspaceBefore = i;
                k = k + 1;
            }
            else if( i == exp.size() - 1){
                next = exp.substr(positionOfspaceBefore + 1,i - positionOfspaceBefore);
            }
            else{
                next = exp.substr(positionOfspaceBefore + 1,i - positionOfspaceBefore - 1);
                positionOfspaceBefore = i;
            }
            if(next =="*" || next == "/" || next == "+" || next == "-"){
                if((!stk.isEmpty()))
                    operand1 = stk.getLastItem();
                if(!stk.isEmpty())
                    operand2 = stk.getLastItem();
                double num1 = strtod(operand1.c_str(), NULL);
                double num2 = strtod(operand2.c_str(), NULL);
                double result;
                if(next == "+"){
                    result = num1 + num2;
                }
                else if(next == "/")
                    result = ( num2 ) / ( num1 );
                else if(next == "-")
                    result = num2 - num1;
                else
                    result = num1 * num2;
            //string strRes = std::to_string(result);
            //string strRes = boost::lexical_cast<string>(result);
            string strRes;          // The string
            ostringstream temp;  // 'temp' as in temporary
            temp << result;
            strRes = temp.str();
            stk.push(strRes);
            }
            else{
                stk.push(next);
            }
        }
        i = i + 1;
    }
    //while(!stk.isEmpty()){
    //    postFix = postFix + " " + stk.getLastItem();
    //}
    double result = strtod(stk.scanLastItem().c_str(), NULL);
    return result;

}



/*int main(){
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
}
*/
