#include "LabOrganizer.h"
#include "iostream"

    LabOrganizer::LabOrganizer(){
        LabOrganizer::numOfCabinets = 0;
        //LabOrganizer::cabinets = new cabinet*[numOfCabinets];
    }
    LabOrganizer::~LabOrganizer(){
        for(int i = 0; i < numOfCabinets; i++){
            delete cabinets[i];
        }if(numOfCabinets > 0){
            delete[] cabinets;
        }
        cabinets = NULL;
    }
    void LabOrganizer::addCabinet(int id, int rows, int columns){
        if(rows > 9 || columns > 9 ){
            cout<<"cabinet cannot be formed. Dimensions are out of bounds"<<endl;
            return;
        }
        if(!isCabinetIdUnique(id)){
            return;
        }
        numOfCabinets++;
        cabinet* cab = new cabinet(id, rows, columns);
        cabinet** newcabinets = new cabinet*[numOfCabinets];
        for(int i = 0; i < numOfCabinets - 1; i++){
            newcabinets[i] = cabinets[i];
            /*
            newcabinets[i].setId(cabinets[i].getId());
            newcabinets[i].setRows(cabinets[i].getRows());
            newcabinets[i].setColumns(cabinets[i].getColumns());
            */
        }
        //deepCopy_2(cabinets, numOfCabinets - 1, newcabinets);
        if(numOfCabinets > 1 ){
            for(int i = 0; i < numOfCabinets - 1; i++){
                //delete cabinets[i];
            }
            delete[] cabinets;
        }

        newcabinets[numOfCabinets - 1] = cab;
        cabinets = newcabinets;
        cout<<"the cabinet with id"<< id << " added "<<"dimesions: "<<rows<<"to"<<columns<<endl;
    }
    void LabOrganizer::removeCabinet(int id){
        int location = findLocationbyId(id);
        if(location == -1){
            std::cout<<"Cabinet does not exist"<<std::endl;
            return;
        }
        cabinet** newcabinets;
        if(numOfCabinets > 1){
            newcabinets = new cabinet*[numOfCabinets - 1];
        }
        for(int i = 0; i < location; i++){
            newcabinets[i] = cabinets[i];
        }
        for(int i = location + 1; i < numOfCabinets; i++ ){
            newcabinets[i - 1] = cabinets[i];
        }
        if(numOfCabinets > 0){
            delete cabinets[location];
            delete[] cabinets;
        }
        cabinets = NULL;
        cabinets = newcabinets;
        numOfCabinets = numOfCabinets - 1;
        newcabinets = NULL;
    }
    void LabOrganizer::listCabinets(){
        for(int i = 0; i < numOfCabinets; i++){
            cabinets[i]->listCabinet();
        }
    }
    void LabOrganizer::cabinetContents(int id){
        int location = findLocationbyId(id);
        if(location == - 1){
            cout<<"the cabinet does not exits"<<endl;
            return;
        }
        cabinets[location]->showCabinetContent();
    }
    void LabOrganizer::placeChemical(int cabinetId, string location, string chemType, int chemID){
        int loca = findLocationbyId(cabinetId);
        int row = getRow(location);
        int column = getColumn(location);
        int type;
        if(chemType[0] == 'c'){
            type = 2;
        }
        if(chemType[0] == 'r'){
            type = 1;
        }

        if(isIdUnique(chemID) == false){
            return;
        }
        Chemical chem(chemID, type);
        if(loca == -1){
            std::cout<<"Cabinet does not exist"<<std::endl;
        }
        else{
            cabinets[loca]->addChemical(row, column, chem);
        }
    }
    void LabOrganizer::findChemical(int id){
        bool found = false;
        for(int i = 0; i < numOfCabinets; i++){
            if(cabinets[i]->findChemicalInCab(id)){
                found = true;
                return;
            }
        }
        if(!found){
            std::cout<<"Chemical cannot be found"<<std::endl;
        }
    }
    void LabOrganizer::removeChemical(int id){
        bool found = false;
        for(int i = 0; i < numOfCabinets; i++){
            if(cabinets[i]->removeChemicalInCab(id)){
                found = true;
                return;
            }
        }
        if(!found){
            std::cout<<"Chemical with id"<<id<<" does not exist"<<std::endl;
        }
    }
    int LabOrganizer::findLocationbyId(int id)const{
        for(int i = 0; i < numOfCabinets; i++ ){
            if(cabinets[i]->getId() == id){
                return i;
            }
        }
        return -1;
    }
    int LabOrganizer::getRow(string s){
        char c = s[0];
        if(c == 'A'){
            return 0;
        }
        else if(c == 'B'){
            return 1;
        }
        else if(c == 'C'){
            return 2;
        }
        else if(c == 'D'){
            return 3;
        }
        else if(c == 'E'){
            return 4;
        }
        else if(c == 'F'){
            return 5;
        }
        else if(c == 'G'){
            return 6;
        }
        else if(c == 'H'){
            return 7;
        }
        else if(c == 'I'){
             return 8;
        }
        else{
            return -1;
        }
        return -1;
    }
    int LabOrganizer::getColumn(string s){
        char c = s[1];
        if(c == '1'){
            return 0;
        }
        else if(c == '2'){
            return 1;
        }
        else if(c == '3'){
            return 2;
        }
        else if(c == '4'){
            return 3;
        }
        else if(c == '5'){
            return 4;
        }
        else if(c == '6'){
            return 5;
        }
        else if(c == '7'){
            return 6;
        }
        else if(c == '8'){
            return 7;
        }
        else if(c == '9'){
            return 8;
        }
        else{
            return -2;
        }
    }
    bool LabOrganizer::isIdUnique(int chemicalId){
        for(int i = 0; i < numOfCabinets; i++){

            if(cabinets[i]->findChemicalInCab2(chemicalId)){
                std::cout<<" chemical with id "<<chemicalId<<" already exists in the system"<<std::endl;
                return false;
            }

        }
        return true;
    }
    bool LabOrganizer::isCabinetIdUnique(int id)const{
        for(int i = 0; i < numOfCabinets; i++){
            if(cabinets[i]->getId() == id){
                std::cout<<"Cabinet with id: "<< id <<" already exists"<<std::endl;
                return false;
            }
        }
        return true;
    }
    void LabOrganizer::deepCopy_2( const cabinet* arr, const int arrSize, cabinet*& output ) {
        output = new cabinet [ arrSize ];
        for (int i = 0; i < arrSize; i++)
            output[ i ] = arr[i];

    }
/*int main(){
    LabOrganizer L;
    L.listCabinets();
    // Testing add cabinet
    cout << "Testing add cabinet" << endl;
    cout << endl;
    L.addCabinet(101, 3, 4);
    L.listCabinets();
    L.cabinetContents(101);
    L.addCabinet(102, 5, 3);
    L.addCabinet(103, 8, 8);
    cout << endl;
    L.cabinetContents(101);
    L.addCabinet(103, 3, 3);
    L.addCabinet(104, 9, 19);
    L.addCabinet(201, 9, 9);
    cout << endl;
    L.addCabinet(203, 9, 3);
    L.addCabinet(205, 4, 4);
    cout << endl;
    //L.cabinetContents(101);
    L.listCabinets();
    cout << endl;
    // Testing remove cabinet
    cout << endl;
    cout << "Testing remove cabinet" << endl;
    cout << endl;
    L.removeCabinet(452);
    L.removeCabinet(101);
    L.removeCabinet(205);
    cout << endl;
    L.removeCabinet(203);
    L.removeCabinet(347);
    L.removeCabinet(201);
    cout << endl;
    L.addCabinet(101, 7, 7);
    cout << endl;
    L.listCabinets();
    cout << endl;
    // Testing place Chemical
    cout << endl;
    cout << "Testing place chemical" << endl;
    cout << endl;
    L.placeChemical( 101, "C1", "combustive", 200);
    //L.placeChemical( 101, "C1", "retardant", 139);
    L.placeChemical( 101, "D3", "retardant", 139);
    cout << endl;
    L.placeChemical( 101, "E3", "combustive", 188);
    L.placeChemical( 101, "C1", "ret", 140);
    L.placeChemical( 101, "D2", "combustive", 888);
    L.cabinetContents(101);
    L.placeChemical(101, "C1","com", 155);
    L.placeChemical( 101, "E1", "combustive", 888);
    L.placeChemical( 102, "B2", "combustive", 200);
    L.placeChemical( 102, "B2", "combustive", 156);
    cout << endl;
    L.placeChemical( 102, "C3", "retardant", 190);
    L.placeChemical( 102, "A3", "combustive", 171);
    L.cabinetContents(102);
    L.placeChemical( 102, "E1", "combustive", 171);
    cout << endl;
    L.placeChemical( 103, "B2", "combustive", 139);
    L.placeChemical( 103, "B2", "combustive", 144);
    L.placeChemical( 103, "C3", "retardant", 120);
    cout << endl;
    L.placeChemical( 103, "A1", "retardant", 127);
    L.placeChemical( 103, "G8", "combustive", 191);
    cout << endl;
    L.listCabinets();
    cout << endl;
    // Testing find chemical
    cout << endl;
    cout << "Testing find chemical" << endl;
    cout << endl;
    L.findChemical(191);
    L.findChemical(156);
    L.findChemical(171);
    cout << endl;
    L.findChemical(155);
    L.findChemical(100);
    L.findChemical(200);
    cout << endl;
    L.findChemical(139);
    cout << endl;
    // Testing show cabinet contents
    cout << endl;
    cout << "Testing show cabinet contents" << endl;
    cout << endl;
    L.cabinetContents(101);
    cout << endl;
    L.cabinetContents(102);
    cout << endl;
    L.cabinetContents(103);
    cout << endl;
    L.cabinetContents(107);
    cout << endl;
    // Testing remove chemical
    cout << endl;
    cout << "Testing remove chemical" << endl;
    cout << endl;
    L.removeChemical(156);
    L.removeChemical(177);
    L.removeChemical(188);
    cout << endl;
    L.removeChemical(189);
    L.removeChemical(777);
    L.removeChemical(127);
    L.removeChemical(200);
    cout << endl;
    L.listCabinets();
    L.cabinetContents(103);
    L.removeCabinet(103);
    cout << endl;
    L.listCabinets();
    L.removeCabinet(102);
    //L.removeCabinet(101);
    L.listCabinets();
    cout <<"123"<<endl;

    L.addCabinet(101,5,5);
    L.addCabinet(101,6,7);
    L.listCabinets();
    L.placeChemical(101,"A1","com",105);
    L.placeChemical(101,"A1","com",106);
    L.placeChemical(101,"A1","ret",106);
    L.placeChemical(101,"A2","com",107);
    L.placeChemical(101,"A2","ret",107);
    L.placeChemical(101,"A3","ret",107);
    L.findChemical(105);
    L.findChemical(107);
    L.cabinetContents(101);
    L.removeCabinet(101);
    L.removeChemical(107);
    L.listCabinets();
    L.cabinetContents(101);
    L.addCabinet(102,6,7);
    L.listCabinets();
    return 0;
}*/

