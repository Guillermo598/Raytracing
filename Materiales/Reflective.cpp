#include "Reflective.h"

Vector3D Reflective::shade(ShadeRec &sr) {
    Vector3D L(Phong::shade(sr));
    Vector3D wo = -sr.rayo.d;
    Vector3D wi = -wo + sr.normal * 2.0 * (sr.normal * wo);
    Vector3D fr = cr * kr / (sr.normal * wi);
    Rayo reflejado(sr.hitPoint, wi);
    L = L + fr.compMult(sr.mundo->pTracer->trace_ray(reflejado, sr.depth + 1)) * (sr.normal * wi);
    return L;
}
