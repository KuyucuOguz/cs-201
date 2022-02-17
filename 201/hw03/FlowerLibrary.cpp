//Oðuz Kuyucu 21902683
#include "FlowerLibrary.h"
#include <iostream>
using namespace std;
FlowerLibrary::FlowerLibrary(){

}
FlowerLibrary::~FlowerLibrary(){
}
void FlowerLibrary::addFlower(string name){
    for(int i = 0; i < name.size(); i++){
        name[i] = tolower(name[i]);
    }
    flowers.add(name);
}
void FlowerLibrary::removeFlower(string name){
    for(int i = 0; i < name.size(); i++){
        name[i] = tolower(name[i]);
    }
    flowers.remove(name);
}
void FlowerLibrary::listFlowers() const{
    flowers.print();
}
void FlowerLibrary::listFeatures(string name) const{
    for(int i = 0; i < name.size(); i++){
        name[i] = tolower(name[i]);
    }
    flowers.printFlower(name);
}
void FlowerLibrary::addFeature(string name,string feature){
    for(int i = 0; i < name.size(); i++){
        name[i] = tolower(name[i]);
    }
    for(int i = 0; i < feature.size(); i++){
        feature[i] = tolower(feature[i]);
    }
    flowers.addFeature(name, feature);
    /*Flower* flower;
    if(flowers.retrieve(name, *flower)){
        (*flower).remove(feature);
    }
    */
}
void FlowerLibrary::removeFeature(string name, string feature){
    flowers.removeFeature(name, feature);
}
void FlowerLibrary::findFlowers(string feature) const{
    flowers.printFlowersWithFeature(feature);
}

