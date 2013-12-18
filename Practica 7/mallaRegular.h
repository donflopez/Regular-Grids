//
//  mallaRegular.h
//  Practica 7
//
//  Created by Francisco López on 17/12/13.
//  Copyright (c) 2013 Francisco López. All rights reserved.
//

#ifndef Practica_7_mallaRegular_h
#define Practica_7_mallaRegular_h

#include <list>
#include <vector>
#include "CodigoPost.h"

template <class T>
class MallaRegular;

template <class U>
class Casilla{
    list<U> puntos;
public:
    friend class MallaRegular<U>;
    Casilla(): puntos(){}
    void inserta (U &dato) { puntos.push_back(dato); }
    bool busca (U &dato);
    bool borra (U &dato);
};

template <class U>
bool Casilla<U>::busca(U& dato){
    typename list<U>::iterator it;
    it = puntos.begin();
    while (it != puntos.end()){
        if (*it == dato)
            return true;
    }
    return false;
}

template <class U>
bool Casilla<U>::borra(U& dato){
    typename list<U>::iterator it;
    it = puntos.begin();
    while (it != puntos.end()){
        if (*it == dato)
            puntos.erase(it);
        return true;
    }
    return false;
}

template <class T>
class MallaRegular {
    float xMin, yMin, xMax, yMax; //tamaño real global
    float tamaCasillaX, tamaCasillaY; //tamaño real de cada casilla
    vector<vector<Casilla<T> > > mr; //vector 2D de casillas
    int densidad;
    Casilla<T> *obtenerCasilla(float x, float y);
public:
    MallaRegular(float aXMin, float aYMin, float aXMax, float aYMax, int aNDiv);
    void insertarDato(float x, float y, T &dato);
    Casilla<T> *buscarDato(float x, float y, T& dato);
    Casilla<T> *borrarDato(float x, float y, T& dato);
    vector<T> buscarRango(float rxmin, float rymin, float rxmax, float rymax);
    int getDensidad(){return densidad;};
};

template <class T>
MallaRegular<T>::MallaRegular(float aXMin, float aYMin, float aXMax, float aYMax, int aNDiv) : xMin(aXMin), yMin(aYMin), xMax(aXMax), yMax(aYMax){
    tamaCasillaX = (xMax-xMin)/aNDiv;
    tamaCasillaY = (yMax-yMin)/aNDiv;
    densidad=0;
    mr.resize(aNDiv+1);
    for(int i=0; i<=aNDiv; i++){
        mr[i].resize(aNDiv+1);
    }
}

template <class T>
Casilla<T> *MallaRegular<T>::obtenerCasilla (float x, float y){
    int i = (x - xMin) / tamaCasillaX;
    int j = (y - yMin) / tamaCasillaY;
    return &mr[i][j];
}
template <class T>
void MallaRegular<T>::insertarDato(float x, float y, T& dato){
    Casilla<T> *c = obtenerCasilla(x,y);
    c->inserta(dato);
    if(densidad<c->puntos.size())
        densidad = c->puntos.size();
}
template <class T>
Casilla<T> *MallaRegular<T>::borrarDato(float x, float y, T& dato){
    Casilla<T> *c = obtenerCasilla(x,y);
    if (c->borra(dato))
        return c;
    return 0;
}

template <class T>
vector<T> MallaRegular<T>::buscarRango(float rxmin, float rymin, float rxmax, float rymax){
    int xmin,ymin,xmax,ymax;
    xmin = (rxmin - xMin) / tamaCasillaX;
    ymin = (rymin - yMin) / tamaCasillaY;
    xmax = (rxmax - xMin) / tamaCasillaX;
    ymax = (rymax - yMin) / tamaCasillaY;
    
    vector<T> points;
    typename list<T>::iterator it;
    
    for (int i=xmin; i<=xmax; i++) {
        for (int j=ymin; j<=ymax; j++) {
            it = mr[i][j].puntos.begin();
            while (it != mr[i][j].puntos.end()){
                if(it->getLat()>=rxmin&&it->getLat()<=rxmax&&it->getLon()>=rymin&&it->getLon()<=rymax){
                    points.push_back(*it);
                }
                it++;
            }
        }
    }
    
    return points;
}

#endif
