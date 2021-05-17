#include "Emisor.h"

Vector3D Emisor::shade(ShadeRec &sr) {
    if (-sr.normal * sr.rayo.d > 0.0)   return c * ls;
    return Vector3D(0,0,0);
}
