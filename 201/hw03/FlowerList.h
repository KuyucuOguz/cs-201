//Oðuz Kuyucu 21902683
#ifndef FLOWERLIST_H
#define FLOWERLIST_H


#include "Flower.h"
class FlowerList{
public:
    FlowerList();
    FlowerList(const FlowerList& aList);
    ~FlowerList();
    bool isEmpty() const;
    int getLength() const;
    bool retrieve(string flowerName, Flower& flower) const;
    bool add(string flowerName);
    bool remove(string flowerName);
    void print()const;
    void printFlowersWithFeature(string feature)const;
    bool addFeature(string flowerName, string feature);
    bool removeFeature(string flowerName, string feature);
    bool printFlower(string FlowerName)const;
private:
    struct FlowerNode{
        Flower f;
        FlowerNode* next;
    };
    int size;
    FlowerNode* head; //the flowers are stored in a sorted singly linear linked list
    // ...
    //you may define additional member functions and data members, if necessary
};


#endif // FLOWERLIST_H
