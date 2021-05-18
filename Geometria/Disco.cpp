#include "Disco.h"

bool Disco::hit(const Rayo &rayo, double &tmin, ShadeRec &sr) const {
    double kEpsilon = 0.005;
    double t = (centro - rayo.o) * normal / (rayo.d * normal);

    Vector3D hitPoint = rayo.o + rayo.d * t;
    if (t > kEpsilon && centro.distancia2(hitPoint) < radio * radio) {
        tmin = t;
        sr.normal = normal;
        sr.localHitPoint = hitPoint;
        return true;
    }
    return false;
}

bool Disco::hit_sombra(const Rayo &rayo, double &tmin) const {
    double kEpsilon = 0.005;
    double t = (centro - rayo.o) * normal / (rayo.d * normal);

    Vector3D hitPoint = rayo.o + rayo.d * t;
    if (t > kEpsilon && centro.distancia2(hitPoint) < radio * radio) {
        tmin = t;
        return true;
    }
    return false;
}

Disco::Disco(Vector3D p, Vector3D n, double r) : centro(p), normal(n), radio(r) {

}

void Disco::move(const Vector3D &v) {
    centro = centro + v;
}

