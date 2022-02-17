//Oðuz Kuyucu 21902683
#include "FlowerList.h"
#include <iostream>
using namespace std;
FlowerList::FlowerList(){
    head = NULL;
    size = 0;
}
FlowerList::FlowerList(const FlowerList& aList){
    size = aList.size;
    head = NULL;
    FlowerNode* current1;
    FlowerNode* current2;
    if(size != 0){
        current1 = aList.head;
        head = new FlowerNode;
        head->f = current1->f;
        current2 = head;
        while(current1->next != NULL){
            current1 = current1->next;
            current2->next = new FlowerNode();
            current2->next->f= current1->f;
            current2 = current2->next;
        }
    }
}
FlowerList::~FlowerList(){
    FlowerNode* current;
    while(size > 0){
        current = head;
        head = head->next;
        delete current;
        size = size - 1;
    }
}
bool FlowerList::isEmpty() const{
    if(size <= 0){
        return true;
    }
    return false;
}
int FlowerList::getLength() const{
    return size;
}
bool FlowerList::retrieve(string flowerName, Flower& flower) const{
    FlowerNode* current = head;
    if(current->f.getName() == flowerName){
        flower = current->f;
        return true;
    }
    while(current->next != NULL){
        if(current->f.getName() == flowerName){
            flower = current->f;
            return true;
        }
        current = current->next;
    }
    if(current->f.getName() == flowerName){
        flower = current->f;
        return true;
    }
    return false;
}
bool FlowerList::add(string flowerName){
    //traverse the list, if flower already exist, return false
    if(size >= 1){
        FlowerNode* traverse = head;
        if(head->f.getName() == flowerName){
            cout<<flowerName<<" already exist in the system"<<endl;
            return false;
        }
        while(traverse->next != NULL){
            if(traverse->f.getName() == flowerName){
                cout<<flowerName<<" already exist in the system"<<endl;
                return false;
            }
        traverse = traverse->next;
        }
        if(traverse->f.getName() == flowerName){
            cout<<flowerName<<" already exist in the system"<<endl;
            return false;
        }
    }
    //form the new node
    FlowerNode* newFlower = new FlowerNode;
    newFlower->f.setName(flowerName);
    newFlower->next = NULL;
    //add it to sorted linked list

    //adding at the beggining of the list
    if(head == NULL){
        head = newFlower;
        size = size + 1;
        cout<<flowerName<<" has been added to library"<<endl;
        return true;
    }
    if(flowerName < head->f.getName()){
        FlowerNode* temp = head;
        head = newFlower;
        newFlower->next = temp;
        size = size + 1;
        cout<<flowerName<<" has been added to library"<<endl;
        return true;
    }
    FlowerNode* current = head;
    FlowerNode* prev;
    while(current->next != NULL){
        prev = current;
        current = current->next;
        if(flowerName < current->f.getName()){
            prev->next = newFlower;
            newFlower->next = current;
            size = size + 1;
            cout<<flowerName<<" has been added to library"<<endl;
            return true;
        }
    }
    //add at the end of the list
    current->next = newFlower;
    size = size + 1;
    cout<<flowerName<<" has been added to library"<<endl;
    return true;
}
bool FlowerList::remove(string flowerName){
    if(size < 1){
        cout<<flowerName<<" does not exist in the system"<<endl;
        return false;
    }
    //delete from start
    FlowerNode* current = head;
    if(current->f.getName() == flowerName){
        head = current->next;
        delete current;
        size = size - 1;
        cout<<flowerName<<" has been removed from the system"<<endl;
        return true;
    }
    //delete from middle
    FlowerNode* prev;
    while (current->next != NULL){
        prev = current;
        current = current->next;
        if(current->f.getName() == flowerName){
            prev->next = current->next;
            delete current;
            size = size - 1;
            cout<<flowerName<<" has been removed from the system"<<endl;
            return true;
        }
    }
    //delete from end
    if(current->f.getName() == flowerName){
        delete current;
        prev->next = NULL;
        size = size - 1;
        cout<<flowerName<<" has been removed from the system"<<endl;
        return true;
    }
    //item does not exist
    else{
        cout<<flowerName<<" does not exist in the system"<<endl;
        return false;
    }
}
struct FlowerNode{
    Flower f;
    FlowerNode* next = NULL;
};
void FlowerList::print()const{
    string s = " ";
    if(size < 1){
        cout<<"There is no flower in the system"<<endl;
        return;
    }
    FlowerNode* current = head;
    while(current->next != NULL){
        cout<<current->f.printFlower()<<endl;
        current = current ->next;
    }
    cout<<current->f.printFlower()<<endl;
}
void FlowerList::printFlowersWithFeature(string feature)const{
    if(size < 1){
        cout<<"there is no flower with the feature "<<feature<<endl;
        return;
    }
    string s = " ";
    int i = 0;
    FlowerNode* current = head;
    while(current->next != NULL){
        if(current->f.detectFeature(feature)){
            if(i == 0){
            s = s + current->f.getName();
            }
            else{
                s = s + ", " + current->f.getName();
            }
            i = i + 1;
        }
        current = current->next;
    }
    if(current->f.detectFeature(feature)){
        if(i == 0){
            s = s + " " + current->f.getName();
        }
        else{
            s = s + ", " + current->f.getName();
        }
    }

    if(s == " "){
        cout<<"there is no flower with the feature "<<feature<<endl;
    }
    else{

        cout<<"flowers with feature "<<feature<<": "<<s<<endl;
    }
}
bool FlowerList::addFeature(string flowerName, string feature){
    FlowerNode* current = head;
    if(current->f.getName() == flowerName){
        current->f.add(feature);
        return true;
    }
    while(current->next != NULL){
        current = current->next;
        if(current->f.getName() == flowerName){
            current->f.add(feature);
            return true;
        }
    }
    if(current->f.getName() == flowerName){
        current->f.add(feature);
        return true;
    }
    cout<<"flower "<<flowerName<<" cannot be found in library"<<endl;
    return false;
}
bool FlowerList::removeFeature(string flowerName, string feature){
    FlowerNode* current = head;
    if(current->f.getName() == flowerName){
        current->f.remove(feature);
        return true;
    }
    while(current->next != NULL){
        current = current->next;
        if(current->f.getName() == flowerName){
            current->f.remove(feature);
            return true;
        }
    }
    if(current->f.getName() == flowerName){
        current->f.remove(feature);
        return true;
    }
    cout<<"flower "<<flowerName<<" cannot be found"<<endl;
    return false;
}
bool FlowerList::printFlower(string flowerName)const{
    FlowerNode* current = head;
    if(current->f.getName() == flowerName){
        cout<<current->f.printFlower()<<endl;
        return true;
    }
    while(current->next != NULL){
        current = current->next;
        if(current->f.getName() == flowerName){
            cout<<current->f.printFlower()<<endl;
            return true;
        }
    }
    if(current->f.getName() == flowerName){
        cout<<current->f.printFlower()<<endl;
        return true;
    }
    cout<<"flower "<<flowerName<<" cannot be found"<<endl;
    return false;
}
