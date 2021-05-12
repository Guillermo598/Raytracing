#include "Plano.h"

Plano::Plano(Vector3D p, Vector3D n) : punto(p), normal(n){

}

bool Plano::hit(const Rayo &rayo, double &tmin, ShadeRec &sr) const {
    double kEpsilon = 0.005;

    double t = (punto - rayo.o) * normal / (rayo.d * normal);
    if (t > kEpsilon) {
        tmin = t;
        sr.normal = normal;
        sr.localHitPoint = rayo.o + rayo.d * t;
        return true;
    }
    return false;
}
