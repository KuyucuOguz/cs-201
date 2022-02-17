//Oðuz Kuyucu 21902683
#ifndef STACK_H
#define STACK_H
#include <string>
const int MAX_STACK_SIZE = 200;
class Stack
{
    public:
        Stack();
        virtual ~Stack();
        bool isEmpty() const;
        bool push(std::string item);
        bool pop();
        bool pop(std::string& oper);
        bool getTop(std::string& oper)const;
        std::string getLastItem();
        std::string scanLastItem()const;
    protected:

    private:
        std::string items[MAX_STACK_SIZE];
        int size;
};

#endif // STACK_H
