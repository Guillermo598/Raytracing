#include "Emisor.h"

Vector3D Emisor::shade(ShadeRec &sr) {
    if (-sr.normal * sr.rayo.d > 0.0)   return c * ls;
    return Vector3D(0,0,0);
}

Emisor::Emisor(Vector3D color, double _ls, Esfera* esfera, LuzPunto* luz) : c(color), ls(_ls), pEsfera(esfera), pLuz(luz){

}

Vector3D Emisor::get_Le(ShadeRec &sr) const {
    return c * ls;
}
