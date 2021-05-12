#include "LuzPunto.h"

Vector3D LuzPunto::get_direccion(ShadeRec &sr) {
    return (posicion - sr.hitPoint).hat();
}

Vector3D LuzPunto::L(ShadeRec &sr) {
    return color * ls;
}

LuzPunto::LuzPunto(Vector3D pos) : posicion(pos), ls(1.0), color(Vector3D(1, 1, 1)) {
}
