#include "Transparent.h"

Vector3D Transparent::shade(ShadeRec &sr) {
    Vector3D L(Phong::shade(sr));
    Vector3D wo = -sr.rayo.d;
    Vector3D wi;
    Vector3D fr = reflective_f(sr, wo, wi);
    Rayo reflejado(sr.hitPoint, wi);

    if (tir(sr)) {
        L = L + sr.mundo->pTracer->trace_ray(reflejado, sr.depth + 1);
    } else {
        Vector3D wt;
        Vector3D ft = specular_f(sr, wo, wt);
        Rayo transmitido(sr.hitPoint, wt);

        L = L + fr.compMult(sr.mundo->pTracer->trace_ray(reflejado, sr.depth + 1)) * abs(sr.normal * wi);
        L = L + ft.compMult(sr.mundo->pTracer->trace_ray(transmitido, sr.depth + 1)) * abs(sr.normal * wt);
    }
    return L;
}

bool Transparent::tir(const ShadeRec &sr) const {
    double cos_thetai = sr.normal * (-sr.rayo.d);
    double eta = ior;
    if (cos_thetai < 0.0)   eta = 1.0 / eta;
    return (1.0 - (1.0 - cos_thetai * cos_thetai) / (eta * eta)) < 0.0;
}

Vector3D Transparent::specular_f(const ShadeRec &sr, const Vector3D &wo, Vector3D &wt) const {
    Vector3D n = sr.normal;
    double cos_thetai = n * wo;
    double eta = ior;
    if (cos_thetai < 0.0) {
        cos_thetai = -cos_thetai;
        n = -n;
        eta = 1.0 / eta;
    }
    double temp = 1.0 - (1.0 - cos_thetai * cos_thetai) / (eta * eta);
    double cos_theta2 = sqrt(temp);
    wt = (-wo / eta) - (n * (cos_theta2 - cos_thetai / eta));
    return Vector3D(1, 1, 1) * (kt / (eta * eta)) / abs(sr.normal * wt);
}

Vector3D Transparent::reflective_f(const ShadeRec &sr, const Vector3D &wo, Vector3D &wi) const {
    double nwo = sr.normal * wo;
    wi = (-wo + sr.normal * nwo * 2);
    return (c * kr / (sr.normal * wi));
}
