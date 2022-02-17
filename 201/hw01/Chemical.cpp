#include "Chemical.h"

Chemical::Chemical(int iid = 0,int typee = 0)
{
    chemid = iid;
    type = typee;
}
Chemical::~Chemical()
{
    //dtor
}
int Chemical::getid(){
    return chemid;
}
int Chemical::getType(){
    return type;
}
void Chemical::setId(int idd ){
    chemid = idd;
}
void Chemical::setType(int typpe){
    type = typpe;
}
/*int chemid;
int type;
*/
