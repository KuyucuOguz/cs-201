//Oðuz Kuyucu 21902683
using namespace std;
#include "Flower.h"
#include <iostream>
#include <string>
Flower::Flower(){
    head = NULL;
    size = 0;
    flowerName = "";
}
Flower::Flower(string flowerName){
    head = NULL;
    size = 0;
    Flower::flowerName = flowerName;
}
Flower::Flower(const Flower& aFlower){
    flowerName = aFlower.flowerName;
    size = aFlower.size;
    head = NULL;
    FeatureNode* current1;
    FeatureNode* current2;
    if(size != 0){
        current1 = aFlower.head;
        head = new FeatureNode();
        head->feature = current1->feature;
        current2 = head;
        while(current1->next != NULL){
            current1 = current1->next;
            current2->next = new FeatureNode();
            current2->next->feature = current1->feature;
            current2 = current2->next;
        }
    }
}
Flower::~Flower(){
    FeatureNode* current;
    while(size > 0){
        current = head;
        head = head->next;
        delete current;
        size = size - 1;
    }
}
bool Flower::isEmpty() const{
    if(size <= 0){
        return true;
    }
    return false;
}
int Flower::getLength() const{
    return size;
}
bool Flower::add(string feature){
    //traverse the list, if feature already exist, return false
    if(size >= 1){
        FeatureNode* traverse = head;
        if(head->feature == feature){

            cout<<feature<<" already exist in "<< flowerName<<endl;
            return false;
        }
        while(traverse->next != NULL){
            traverse = traverse->next;
            if(traverse->feature == feature){
                cout<<feature<<" already exist in "<< flowerName<<endl;
                return false;
            }
        }
        if(traverse->feature == feature){
            cout<<feature<<" already exist in "<< flowerName<<endl;
            return false;
        }
    }
    //form the new node
    FeatureNode* newFeature = new FeatureNode;
    newFeature->feature = feature;
    newFeature->next = NULL;
    //add it to sorted linked list

    //adding at the beggining of the list
    if(size == 0){
        head = newFeature;
        cout<<feature<<" is added into "<<flowerName<<endl;
        size = size + 1;
        return true;
    }
    if(feature < head->feature ){
        FeatureNode* temp = head;
        head = newFeature;
        newFeature->next = temp;
        size = size + 1;
        cout<<feature<<" is added into "<<flowerName<<endl;
        return true;
    }
    FeatureNode* current = head;
    FeatureNode* prev;
    while(current->next != NULL){
        prev = current;
        current = current->next;
        if(feature < current->feature){
            prev->next = newFeature;
            newFeature->next = current;
            size = size + 1;
            cout<<feature<<" is added into "<<flowerName<<endl;
            return true;
        }

    }
    //add at the end of the list
    current->next = newFeature;
    size = size + 1;
    cout<<feature<<" is added into "<<flowerName<<endl;
    return true;
}
bool Flower::remove(string feature){
    if(size < 1){
        return false;
    }
    //delete from start
    FeatureNode* current = head;
    if(current->feature == feature){
        head = current->next;
        delete current;
        size = size - 1;
        cout<<feature<<" is removed from "<< flowerName<<endl;
        return true;
    }
    //delete from middle
    FeatureNode* prev;
    while (current->next != NULL){
        prev = current;
        current = current->next;
        if(current->feature == feature){
            prev->next = current->next;
            delete current;
            size = size - 1;
            cout<<feature<<" is removed from "<< flowerName<<endl;
            return true;
        }
    }
    //delete from end
    if(current->feature == feature){
        delete current;
        prev->next = NULL;
        size = size - 1;
        cout<<feature<<" is removed from "<< flowerName<<endl;
        return true;
    }
    //item does not exist
    else{
        cout<<feature<<" does not exist in "<< flowerName<<endl;
        return false;
    }

}
string Flower::printFlower() const{
    string s = " ";
    FeatureNode* current = head;
    int i = 0;
    if(size <= 0){
        return flowerName + ": no feature" ;
    }
    while(current->next != NULL){
        if(i == 0 ){
        s = current->feature;
        }
        else{
            s = s + ", " + current->feature;
        }
        current = current->next;
        i = i + 1;
    }
    if(i == 0){
        s = s + " " + current->feature ;
    }
    else{
        s = s + ", " + current->feature;
    }
    return flowerName + " features: " + s;
}
string Flower::getName() const{
    return flowerName;
}
struct FeatureNode{
    string feature;
    FeatureNode* next = NULL;
};

void Flower::setName(string Name){
    flowerName = Name;
}

bool Flower::detectFeature(string feature) const{
    if(size < 1){
        return false;
    }
    FeatureNode* current;
    current = head;
    while(current->next != NULL){
        if(current->feature == feature){
            return true;
        }
        current = current->next;
    }
    if(current->feature == feature){
        return true;
    }
    return false;
}

