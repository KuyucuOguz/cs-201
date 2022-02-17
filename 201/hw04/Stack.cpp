//Oðuz Kuyucu 21902683
#include "Stack.h"
#include <string>
using namespace std;
Stack::Stack(): size(-1)
{
    //ctor
}

Stack::~Stack()
{
    //dtor
}

bool Stack::isEmpty()const{
    return size < 0;
}
bool Stack::push(std::string item){
    if(size >= MAX_STACK_SIZE -1){
        return false;
    }
    else{
        size++;
        items[size] = item;
        return true;
    }
}
bool Stack::pop(){
    if(isEmpty()){
        return false;
    }
    else{
        size = size - 1;
        return true;
    }

}
bool Stack::pop(std::string& oper){
    if(isEmpty()){
        return false;
    }
    else{
        oper = items[size];
        size--;
        return true;
    }

}
bool Stack::getTop(std::string& oper)const{
    if(isEmpty()){
        return false;
    }
    else{
        oper = items[size];
        return true;
    }
}

string Stack::getLastItem(){
    string item = items[size];
    size--;
    return item;
}
string Stack::scanLastItem() const{
    return items[size];
}
