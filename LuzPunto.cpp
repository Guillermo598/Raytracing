#include "LuzPunto.h"

Vector3D LuzPunto::get_direccion(ShadeRec &sr) {
    return (posicion - sr.hitPoint).hat();
}

Vector3D LuzPunto::L(ShadeRec &sr) {
    return color * ls;
}

LuzPunto::LuzPunto(Vector3D pos) : posicion(pos), ls(1.0), color(Vector3D(1, 1, 1)) {
}

bool LuzPunto::en_sombra(const Rayo &rayo, const ShadeRec &sr) const {
    double t;
    double d = posicion.distancia(rayo.o);

    for (auto& objeto : sr.mundo->objetos) {
        if (objeto->hit_sombra(rayo, t) && t < d)
            return true;
    }
    return false;
}

void LuzPunto::set_color(Vector3D c) {
    color = c;
}
