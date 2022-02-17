#include "cabinet.h"
#include "iostream"
/*int id;
int rows;
int columns;
Chemical** chemicals;
*/
cabinet::cabinet(){
/*    cabinet::id = 0;
    cabinet::rows = 0;
    cabinet::columns = 0;
    cabinet::chemicals = nullpt;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            chemicals[i][j] = ;
        }
    }
*/
}
cabinet::cabinet(int iid , int rowss, int columnss){
   id = iid;
   rows = rowss;
   columns = columnss;
   chemicals = new Chemical**[rows];
   for(int i = 0; i < rows; i++){
        chemicals[i] = new Chemical*[columns];
   }
   for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            chemicals[i][j] = NULL;
        }
   }
}
cabinet::~cabinet(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(chemicals[i][j] == NULL){
                continue;
            }
            else{
                std::cout<<"chemical "<<chemicals[i][j]->getid()<<" is removed from cabinet "<<id<<std::endl;
                delete chemicals[i][j];
            }
        }
        delete[] chemicals[i];
    }

    //for(int i = 0; i < rows; i++){
    //    delete[] chemicals[i];
    //}
    delete[] chemicals;
    std::cout<<"cabinet with id:"<< id <<" deleted"<<std::endl;
    chemicals = NULL;
 }
bool cabinet::comPlacable2(int row, int column){
    if(!isExist(row, column)){
        return false;
    }
    if(!isAvailable(row, column)){
        return false;
    }
    if(isExist(row + 1, column - 1)){
        if(chemicals[row+1][column - 1] != NULL){
            if(chemicals[row + 1][column - 1]->getType() == 2){
                std::cout<<"combustive cannot be added"<<std::endl;
                return false;
            }
        }
    }
    if(isExist(row + 1, column )){
        if(chemicals[row+1][column] != NULL){
            if(chemicals[row + 1][column]->getType() == 2){
                std::cout<<"combustive cannot be added"<<std::endl;
                return false;
            }
        }
    }
    if(isExist(row + 1, column + 1 )){
        if(chemicals[row+1][column + 1] != NULL){
            if(chemicals[row + 1][column + 1]->getType() == 2){
                std::cout<<"combustive cannot be added"<<std::endl;
                return false;
            }
        }
    }
    if(isExist(row , column - 1)){
        if(chemicals[row][column - 1] != NULL){
            if(chemicals[row ][column - 1]->getType() == 2){
                std::cout<<"combustive cannot be added"<<std::endl;
                return false;
            }
        }
    }
    if(isExist(row , column + 1)){
        if(chemicals[row][column + 1] != NULL){
            if(chemicals[row][column + 1]->getType() == 2){
                std::cout<<"combustive cannot be added"<<std::endl;
                return false;
            }
        }
    }
    if(isExist(row - 1, column - 1)){
        if(chemicals[row - 1][column - 1] != NULL){
            if(chemicals[row - 1][column - 1]->getType() == 2){
                std::cout<<"combustive cannot be added"<<std::endl;
                return false;
            }
        }
    }
    if(isExist(row - 1, column)){
        if(chemicals[row-1][column] != NULL){
            if(chemicals[row - 1][column]->getType() == 2){
                std::cout<<"combustive cannot be added"<<std::endl;
                return false;
            }
        }
    }
    if(isExist(row - 1, column + 1)){
        if(chemicals[row-1][column + 1] != NULL){
            if(chemicals[row - 1][column + 1]->getType() == 2){
                std::cout<<"combustive cannot be added"<<std::endl;
                return false;
            }
        }
    }

    /*if(chemicals[row + 1][column - 1]->getType() == 2 || chemicals[row + 1][column]->getType() == 2 || chemicals[row + 1][column + 1]->getType() == 2
        || chemicals[row][column - 1]->getType() == 2 || chemicals[row][column + 1]->getType() == 2 ||
    chemicals[row - 1][column + 1]->getType() == 2 || chemicals[row - 1][column]->getType() == 2 || chemicals[row - 1][column - 1]->getType() == 2){
        return false;
    }
    */
    return true;
}
bool cabinet::comPlacable(int row, int column){
    if(!isExist(row, column)){
        return false;
    }
    if(!isAvailable(row, column)){
        return false;
    }
    if(isExist(row + 1, column - 1)){
        if(chemicals[row+1][column - 1] != NULL){
            if(chemicals[row + 1][column - 1]->getType() == 2){
                return false;
            }
        }
    }
    if(isExist(row + 1, column )){
        if(chemicals[row+1][column] != NULL){
            if(chemicals[row + 1][column]->getType() == 2){
                return false;
            }
        }
    }
    if(isExist(row + 1, column + 1 )){
        if(chemicals[row+1][column + 1] != NULL){
            if(chemicals[row + 1][column + 1]->getType() == 2){
                return false;
            }
        }
    }
    if(isExist(row , column - 1)){
        if(chemicals[row][column - 1] != NULL){
            if(chemicals[row ][column - 1]->getType() == 2){
                return false;
            }
        }
    }
    if(isExist(row , column + 1)){
        if(chemicals[row][column + 1] != NULL){
            if(chemicals[row][column + 1]->getType() == 2){
                return false;
            }
        }
    }
    if(isExist(row - 1, column - 1)){
        if(chemicals[row-1][column - 1] != NULL){
            if(chemicals[row - 1][column - 1]->getType() == 2){
                return false;
            }
        }
    }
    if(isExist(row - 1, column)){
        if(chemicals[row-1][column] != NULL){
            if(chemicals[row - 1][column]->getType() == 2){
                return false;
            }
        }
    }
    if(isExist(row - 1, column + 1)){
        if(chemicals[row-1][column + 1] != NULL){
            if(chemicals[row - 1][column + 1]->getType() == 2){
                return false;
            }
        }
    }

    /*if(chemicals[row + 1][column - 1]->getType() == 2 || chemicals[row + 1][column]->getType() == 2 || chemicals[row + 1][column + 1]->getType() == 2
        || chemicals[row][column - 1]->getType() == 2 || chemicals[row][column + 1]->getType() == 2 ||
    chemicals[row - 1][column + 1]->getType() == 2 || chemicals[row - 1][column]->getType() == 2 || chemicals[row - 1][column - 1]->getType() == 2){
        return false;
    }
    */
    return true;
}
bool cabinet::isExist(int row, int column)const{
    if(row >= rows || column >= columns || row < 0 || column < 0){
        return false;
    }
    return true;
}
bool cabinet::isAvailable(int row, int column)const{
    if(chemicals[row][column] == NULL){
        return true;
    }
    //std::cout<<"The place is occupied"<<std::endl;
    return false;
}
bool cabinet::isCombustivePlaceable(int row, int column){
    bool b = false;
    std::string s = "";
    if(!comPlacable(row,column)){
        for(int r = row - 1; r <= row + 1; r++ ){
            for(int c = column - 1; c <= column + 1; c++){
                if(isExist(r,c)){
                    if(comPlacable(r, c)){
                        s = s + getRow(r) + getColumn(c) + " ";
                        b = true;
                        //std::cout<< "location "<<row<<"x"<<column<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" << getRow(r) << c <<std::endl;
                    }
                }
            }
        }
        if(b){
            std::cout<< "location "<<getRow(row)<<"x"<<column + 1<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" <<s<<std::endl;
            return false;
        }
        for(int r = row - 2; r <= row + 2; r++ ){
            for(int c = column - 2; c <= column + 2; c++){
                if(isExist(r,c)){
                    if(comPlacable(r, c)){
                        s = s + getRow(r) + getColumn(c) + " ";
                        b = true;
                    }
                }
            }
        }
        if(b){
            std::cout<< "location "<<getRow(row)<<"x"<<column + 1<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" <<s<<std::endl;
            return false;
        }
        for(int r = row - 3; r <= row + 3; r++ ){
            for(int c = column - 3; c <= column + 3; c++){
                if(isExist(r,c)){
                    if(comPlacable(r, c)){
                        s = s + getRow(r) + getColumn(c) + " ";
                        b = true;

                    }
                }
            }
        }
        if(b){
            std::cout<< "location "<<getRow(row)<<"x"<<column + 1<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" <<s<<std::endl;
            return false;
        }
        for(int r = row - 4; r <= row + 4; r++ ){
            for(int c = column - 4; c <= column + 4; c++){
                if(isExist(r,c)){
                    if(comPlacable(r, c)){
                        s = s + getRow(r) + getColumn(c) + " ";
                        b = true;
                        //std::cout<< "location "<<row<<"x"<<column<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" << getRow(r) << c <<std::endl;
                    }
                }
            }
        }
        if(b){
            std::cout<< "location "<<getRow(row)<<"x"<<column + 1<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" <<s<<std::endl;
            return false;
        }
        for(int r = row - 5; r <= row + 5; r++ ){
            for(int c = column - 5; c <= column + 5; c++){
                if(isExist(r,c)){
                    if(comPlacable(r, c)){
                        s = s + getRow(r) + getColumn(c) + " ";
                        b = true;
                        //std::cout<< "location "<<row<<"x"<<column<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" << getRow(r) << c <<std::endl;
                    }
                }
            }
        }
        if(b){
            std::cout<< "location "<<getRow(row)<<"x"<<column + 1<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" <<s<<std::endl;
            return false;
        }
        for(int r = row - 6; r <= row + 6; r++ ){
            for(int c = column - 6; c <= column + 6; c++){
                if(isExist(r,c)){
                    if(comPlacable(r, c)){
                        s = s + getRow(r) + getColumn(c) + " ";
                        b = true;
                        //std::cout<< "location "<<row<<"x"<<column<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" << getRow(r) << c <<std::endl;
                    }
                }
            }
        }
        if(b){
            std::cout<< "location "<<getRow(row)<<"x"<<column + 1<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" <<s<<std::endl;
            return false;
        }
        for(int r = row - 7; r <= row + 7; r++ ){
            for(int c = column - 7; c <= column + 7; c++){
                if(isExist(r,c)){
                    if(comPlacable(r, c)){
                        s = s + getRow(r) + getColumn(c) + " ";
                        b = true;
                        //std::cout<< "location "<<row<<"x"<<column<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" << getRow(r) << c <<std::endl;
                    }
                }
            }
        }
        if(b){
            std::cout<< "location "<<getRow(row)<<"x"<<column + 1<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" <<s<<std::endl;
            return false;
        }
        for(int r = row - 8; r <= row + 8; r++ ){
            for(int c = column - 8; c <= column + 8; c++){
                if(comPlacable(r, c)){
                    s = s + getRow(r) + getColumn(c) + " ";
                    b = true;
                    //std::cout<< "location "<<row<<"x"<<column<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" << getRow(r) << c <<std::endl;
                }
            }
        }
        std::cout<< "location "<<getRow(row)<<"x"<<column + 1<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" <<s<<std::endl;
        return false;
    }
    return true;
}
void cabinet::addChemical(int row, int column, Chemical chem){

    if(chem.getType() == 1){
        if(isAvailable(row, column)){
            Chemical* chemi = new Chemical(chem.getid(),chem.getType());
            chemicals[row][column] = chemi;
            std::cout<<"the reterdant chemical with id:"<<chem.getid()<<" is added"<<" in cabinet with id "<<id<<" in "<<getRow(row)<<getColumn(column)<<std::endl;
            return;
        }
        else{
            isReterdandPlaceable(row,column);
            return;
        }
    }
    if(chem.getType() == 2){
        if(isCombustivePlaceable2(row, column)){
            if(isCombustivePlaceable(row,column)){
                Chemical* chemi = new Chemical(chem.getid(),chem.getType());
                chemicals[row][column] = chemi;
                std::cout<<"the combustive chemical with id:"<<chem.getid()<<" is added "<<" in cabinet with id "<<id<<" in "<<getRow(row)<<getColumn(column)<<std::endl;
                return;
            }
        }
    }
}
int cabinet::getId() const{
    return id;
}
void cabinet::listCabinet() const{
    int numOfEmpty = 0;
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < columns; c++){
            if(chemicals[r][c] == NULL){
                numOfEmpty++;
            }
        }
    }
    std::cout<<"id: "<<id<<"dimensions: " << rows <<" to "<< columns<<" Empty slots :" << numOfEmpty<< std::endl;
}
void cabinet::showCabinetContent() const{
    int emptySlots = 0;
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < columns; c++){
            if(chemicals[r][c] == NULL)
                emptySlots++;
        }
    }
    std::cout<< "id:"<<id<<",   "<< rows << "x"<<columns<<"   ,"<<"Empty:"<<emptySlots<<",   Chemicals:";
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < columns; c++){
            if(chemicals[r][c] != NULL)
                std::cout<<getRow(r)<<c + 1<<":"<<chemicals[r][c]->getid()<<"   ";
        }
    }
    std::cout<<std::endl;
    std::cout<<"   ";
    for(int c = 0; c < columns; c++){
        std::cout<<"  "<<c + 1<<"  ";
    }
    std::cout<<std::endl;
    for(int r = 0; r < rows; r++){
            if(r ==0){
                std::cout<<"A  ";
            }
            if(r == 1){
                std::cout<<"B  ";
            }
            if(r == 2){
                std::cout<<"C  ";
            }
            if(r == 3){
                std::cout<<"D  ";
            }
            if(r == 4){
                std::cout<<"E  ";
            }
            if(r == 5){
                std::cout<<"F  ";
            }
            if(r == 6){
                std::cout<<"G  ";
            }
            if(r == 7){
                std::cout<<"H  ";
            }
            if(r == 8){
                std::cout<<"I  ";
            }
        for(int c = 0; c < columns; c++){
            if(chemicals[r][c] == NULL)
                std::cout<<"  +  ";
            else if(chemicals[r][c]->getType() == 1)
                std::cout<<"  r  ";
            else if(chemicals[r][c]->getType() == 2){
                std::cout<<"  c  ";
            }
            else{
                std::cout<<"  e  ";
            }

        }
        std::cout<<std::endl;
    }
}
bool cabinet::findChemicalInCab(int chemid){
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < columns; c++){
            if(chemicals[r][c] != NULL){
                if(chemicals[r][c]->getid() == chemid){
                    std::cout<<"the chemical with id:"<<chemid<<" is in the cabinet with id: "<<id<<" in "<<getRow(r)<<c + 1<<std::endl;
                    return true;
                }
            }
        }
    }
    return false;
}
bool cabinet::removeChemicalInCab(int id){
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < columns; c++){
           if(chemicals[r][c] != NULL){
                if(chemicals[r][c]->getid() == id){
                    delete chemicals[r][c];
                    chemicals[r][c] = NULL;
                    std::cout<<"chemical with id:"<<id<<" is removed from cabinet "<<cabinet::id<<std::endl;
                    return true;
                }
           }
        }
    }
    return false;
}
int cabinet::getRows() const{
    return rows;
}
int cabinet::getColumns() const{
    return columns;
}
void cabinet::setId(int iidd){
    id = iidd;
}
void cabinet::setRows(int rrows){
    rows = rrows;
}
void cabinet::setColumns(int ccolumns){
    columns = ccolumns;
}
/*bool cabinet::isExistAvailableAndPlacableinCab(int row, int column)const{
        if(rows > row && columns > column){
            return false;
        }
            if(chemicals[row][column].getType() != 0){
                return false;
        }
        if(chemicals[row][column].getType() == 2){
            if(chemicals[row + 1][column - 1].getType() == 2 || chemicals[row + 1][column].getType() == 2 || chemicals[row + 1][column + 1].getType() == 2
                || chemicals[row][column - 1].getType() == 2 || chemicals[row][column + 1].getType() == 2 ||
            chemicals[row - 1][column + 1].getType() == 2 || chemicals[row - 1][column].getType() == 2 || chemicals[row - 1][column - 1].getType() == 2){
                return false;

            }
        }
        return true;
}
*/
char cabinet::getRow(int row)const{
    if(row == 0){
        return 'A';
    }
    if(row == 1){
        return 'B';
    }
    if(row == 2){
        return 'C';
    }
    if(row == 3){
        return 'D';
    }
    if(row == 4){
        return 'E';
    }
    if(row == 5){
        return 'F';
    }
    if(row == 6){
        return 'G';
    }
    if(row == 7){
        return 'H';
    }
    if(row == 8){
        return 'I';
    }
    return 'Z';
}
char cabinet::getColumn(int column)const{
    if(column == 0){
        return '1';
    }
    if(column == 1){
        return '2';
    }
    if(column == 2){
        return '3';
    }
    if(column == 3){
        return '4';
    }
    if(column == 4){
        return '5';
    }
    if(column == 5){
        return '6';
    }
    if(column == 6){
        return '7';
    }
    if(column == 7){
        return '8';
    }
    if(column == 8){
        return '9';
    }
    return 'a';
}
void cabinet::isReterdandPlaceable(int row, int column){
    bool b = false;
    std::string s = "";
    for(int a = 1; a <= 8; a++){
        for(int r = row - a; r <= row + a; r++ ){
            for(int c = column - a; c <= column + a; c++){
                if(isExist(r,c) && chemicals[r][c] == NULL){
                    s = s + getRow(r) + getColumn(c) + "  ";
                    b = true;
                }
            }
        }
        if(b){
            std::cout<<"The place is occupied, nearest positions for this chemical are: "<<s<<std::endl;
            return;
        }
    }
}
bool cabinet::findChemicalInCab2(int chemid){


    for(int r = 0; r < rows; r++){
        for(int c = 0; c < columns; c++){
            if(chemicals[r][c] != NULL){
                if(chemicals[r][c]->getid() == chemid){
                    //std::cout<<"the chemical is in the cabinet with id: "<<chemid<<" in "<<getRow(r)<<c + 1<<std::endl;
                    return true;
                }
            }
        }
    }
    return false;
}
bool cabinet::isCombustivePlaceable2(int row, int column){
    bool b = false;
    std::string s = "";
    if(!isAvailable(row, column)){
        for(int r = row - 1; r <= row + 1; r++ ){
            for(int c = column - 1; c <= column + 1; c++){
                if(isExist(r,c)){
                    if(comPlacable(r, c)){
                        s = s + getRow(r) + getColumn(c) + " ";
                        b = true;
                        //std::cout<< "location "<<row<<"x"<<column<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" << getRow(r) << c <<std::endl;
                    }
                }
            }
        }
        if(b){
            std::cout<< "location "<<getRow(row)<<"x"<<column + 1<<" in cabinet "<< id <<" is already occupied, nearest positions for this chemical are:" <<s<<std::endl;
            return false;
        }
        for(int r = row - 2; r <= row + 2; r++ ){
            for(int c = column - 2; c <= column + 2; c++){
                if(isExist(r,c)){
                    if(comPlacable(r, c)){
                        s = s + getRow(r) + getColumn(c) + " ";
                        b = true;
                    }
                }
            }
        }
        if(b){
            std::cout<< "location "<<getRow(row)<<"x"<<column + 1<<" in cabinet "<< id <<" is already occupied, nearest positions for this chemical are:" <<s<<std::endl;
            //std::cout<< "location "<<getRow(row)<<"x"<<column + 1<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" <<s<<std::endl;
            return false;
        }
        for(int r = row - 3; r <= row + 3; r++ ){
            for(int c = column - 3; c <= column + 3; c++){
                if(isExist(r,c)){
                    if(comPlacable(r, c)){
                        s = s + getRow(r) + getColumn(c) + " ";
                        b = true;

                    }
                }
            }
        }
        if(b){
            std::cout<< "location "<<getRow(row)<<"x"<<column + 1<<" in cabinet "<< id <<" is already occupied, nearest positions for this chemical are:" <<s<<std::endl;
            //std::cout<< "location "<<getRow(row)<<"x"<<column + 1<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" <<s<<std::endl;
            return false;
        }
        for(int r = row - 4; r <= row + 4; r++ ){
            for(int c = column - 4; c <= column + 4; c++){
                if(isExist(r,c)){
                    if(comPlacable(r, c)){
                        s = s + getRow(r) + getColumn(c) + " ";
                        b = true;
                        //std::cout<< "location "<<row<<"x"<<column<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" << getRow(r) << c <<std::endl;
                    }
                }
            }
        }
        if(b){
            std::cout<< "location "<<getRow(row)<<"x"<<column + 1<<" in cabinet "<< id <<" is already occupied, nearest positions for this chemical are:" <<s<<std::endl;
            //std::cout<< "location "<<getRow(row)<<"x"<<column + 1<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" <<s<<std::endl;
            return false;
        }
        for(int r = row - 5; r <= row + 5; r++ ){
            for(int c = column - 5; c <= column + 5; c++){
                if(isExist(r,c)){
                    if(comPlacable(r, c)){
                        s = s + getRow(r) + getColumn(c) + " ";
                        b = true;
                        //std::cout<< "location "<<row<<"x"<<column<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" << getRow(r) << c <<std::endl;
                    }
                }
            }
        }
        if(b){
            std::cout<< "location "<<getRow(row)<<"x"<<column + 1<<" in cabinet "<< id <<" is already occupied, nearest positions for this chemical are:" <<s<<std::endl;
            //std::cout<< "location "<<getRow(row)<<"x"<<column + 1<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" <<s<<std::endl;
            return false;
        }
        for(int r = row - 6; r <= row + 6; r++ ){
            for(int c = column - 6; c <= column + 6; c++){
                if(isExist(r,c)){
                    if(comPlacable(r, c)){
                        s = s + getRow(r) + getColumn(c) + " ";
                        b = true;
                        //std::cout<< "location "<<row<<"x"<<column<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" << getRow(r) << c <<std::endl;
                    }
                }
            }
        }
        if(b){
            std::cout<< "location "<<getRow(row)<<"x"<<column + 1<<" in cabinet "<< id <<" is already occupied, nearest positions for this chemical are:" <<s<<std::endl;
            //std::cout<< "location "<<getRow(row)<<"x"<<column + 1<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" <<s<<std::endl;
            return false;
        }
        for(int r = row - 7; r <= row + 7; r++ ){
            for(int c = column - 7; c <= column + 7; c++){
                if(isExist(r,c)){
                    if(comPlacable(r, c)){
                        s = s + getRow(r) + getColumn(c) + " ";
                        b = true;
                        //std::cout<< "location "<<row<<"x"<<column<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" << getRow(r) << c <<std::endl;
                    }
                }
            }
        }
        if(b){
            std::cout<< "location "<<getRow(row)<<"x"<<column + 1<<" in cabinet "<< id <<" is already occupied, nearest positions for this chemical are:" <<s<<std::endl;
            //std::cout<< "location "<<getRow(row)<<"x"<<column + 1<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" <<s<<std::endl;
            return false;
        }
        for(int r = row - 8; r <= row + 8; r++ ){
            for(int c = column - 8; c <= column + 8; c++){
                if(comPlacable(r, c)){
                    s = s + getRow(r) + getColumn(c) + " ";
                    b = true;
                    //std::cout<< "location "<<row<<"x"<<column<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" << getRow(r) << c <<std::endl;
                }
            }
        }
        std::cout<< "location "<<getRow(row)<<"x"<<column + 1<<" in cabinet "<< id <<" is already occupied, nearest positions for this chemical are:" <<s<<std::endl;
        //std::cout<< "location "<<getRow(row)<<"x"<<column + 1<<" in cabinet "<< id <<" is not suitable for a combustive chemical  nearest positions are:" <<s<<std::endl;
        return false;
    }
    return true;
}
