//
//  CodigoPost.h
//  Practica4
//
//  Created by Francisco López on 13/11/13.
//  Copyright (c) 2013 Francisco López. All rights reserved.
//

#ifndef Practica4_CodigoPost_h
#define Practica4_CodigoPost_h

#include <sstream>
#include <list>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


using namespace std;

class CodigoPost {
    string zipcode;
    unsigned long int tax, pop, wages;
    double lat, longi;
    string zipType, city, state, locType, loc, decomm;
    
public:
    CodigoPost(string codigo, string tipo, string city, string state, string tipo2, double numlon, double numlat):zipcode(codigo),zipType(tipo),city(city),state(state),locType(tipo2),longi(numlon),lat(numlat){};
    string getCity(){return city;};
    double getLat(){return lat;};
    double getLon(){return longi;};
    void showCity();
};

void CodigoPost::showCity(){
    cout << endl;
    cout << BOLDRED << "Nombre: " << RESET << BOLDCYAN << city << RESET <<endl;
    cout << BOLDRED << "Estado: " << RESET << BOLDMAGENTA << state << RESET << endl;
    /*cout << "Localización: " << loc << endl;
    cout << "Tipo de Localización: " << locType << endl;
    cout << "Coordenadas: " << lat << "Lat" << longi << "Long" <<endl;
    cout << "Desarmado: " << decomm << endl;
    cout << "CP: " << zipcode << endl;
    cout << "Tipo CP: " << zipType << endl;
    cout << "Impuestos delcarados: " << tax << endl;
    cout << "Población: " << pop << endl;
    cout << "Salarios totales: " << wages << endl;*/
    cout << endl;
}

struct StructPost {
    string ciudad;
    list<CodigoPost> codigos;
    bool operator<(const StructPost &cp){
        return (ciudad < cp.ciudad);
    }
    bool operator>(const StructPost &cp){
        return (ciudad > cp.ciudad);
    }
    bool operator==(const StructPost &cp){
        return (ciudad == cp.ciudad);
    }
};

#endif