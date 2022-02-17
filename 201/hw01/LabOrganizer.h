#ifndef LABORGANIZER_H
#define LABORGANIZER_H
#include "cabinet.h"
#include "Chemical.h"
#include <string>
using namespace std;
class LabOrganizer
{
public:
    LabOrganizer();
    ~LabOrganizer();
    void addCabinet(int id, int rows, int columns);
    void removeCabinet(int id);
    void listCabinets();
    void cabinetContents(int id);
    void placeChemical(int cabinetId, string location, string chemType, int chemID);
    void findChemical(int id);
    void removeChemical(int id);

    // ...
    //you may define additional member functions and data members, if necessary
private:
        int findLocationbyId(int id)const;
        int getRow(string s);
        int getColumn(string s);
        bool isIdUnique(int chemicalId);
        bool isExistAvailableAndPlacable(int id, int row, int column);
        bool isCabinetIdUnique(int id) const;
        void deepCopy_2( const cabinet* arr, const int arrSize, cabinet*& output );
        cabinet** cabinets;
        int numOfCabinets;
};

#endif // LABORGANIZER_H
