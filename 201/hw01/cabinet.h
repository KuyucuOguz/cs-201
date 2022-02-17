#ifndef CABINET_H
#define CABINET_H
#include "Chemical.h"
#include <string>
class cabinet
{
    public:
        cabinet();
        cabinet(int id, int rows, int columns);
        virtual ~cabinet();
        void addChemical(int row, int column, Chemical chem);
        bool isExistAvailableAndPlacableinCab(int row, int column)const;
        bool isPlaceable()const;
        void showCabinetContent()const;
        bool findChemicalInCab(int id);
        bool removeChemicalInCab(int id) ;
        int getId()const;
        bool isCombustivePlaceable(int row, int column);
        //bool isExistAvailableAndPlacableinCab(int row, int column)const;
        bool comPlacable2(int row, int column);
        bool comPlacable(int row, int column);
        bool isExist(int row, int column)const;
        bool isAvailable(int row, int column)const;
        void listCabinet()const;
        int getRows() const;
        int getColumns() const;
        void setId(int);
        void setRows(int);
        void setColumns(int);
        char getRow(int)const;
        char getColumn(int)const;
        void isReterdandPlaceable(int row, int column);
        bool findChemicalInCab2(int chemid);
        bool isCombustivePlaceable2(int row, int column);
    private:
        Chemical*** chemicals;
        int id;
        int rows;
        int columns;

};

#endif // CABINET_H
