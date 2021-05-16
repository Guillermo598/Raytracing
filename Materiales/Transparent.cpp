#include "Transparent.h"

Vector3D Transparent::shade(ShadeRec &sr) {
    Vector3D L(Phong::shade(sr));
    Vector3D wo = sr.rayo.d * (-1);
    double nwo = sr.normal * wo;
    Vector3D wi = wo * (-1) + sr.normal * nwo * 2.0;
    Vector3D fr = c * kr / (sr.normal * wi);
    Rayo reflejado(sr.hitPoint, wi);

    double cos_thetai = nwo;
    double eta = ior;
    if (cos_thetai < 0.0)   eta = 1.0 / eta;
    bool tir = (1.0 - (1.0 - cos_thetai * cos_thetai) / (eta * eta)) < 0.0;

    if (tir) {
        L = L + sr.mundo->pTracer->trace_ray(reflejado, sr.depth + 1);
    } else {
        Vector3D n = sr.normal;
        if (cos_thetai < 0.0) {
            cos_thetai = cos_thetai * (-1);
            n = n * (-1);
        }
        double temp = 1.0 - (1.0 - cos_thetai * cos_thetai) / (eta * eta);
        double cos_theta2 = sqrt(temp);
        Vector3D wt = (wo * (-1) / eta) - (n * (cos_theta2 - cos_theta2 / eta));
        Vector3D ft = Vector3D(1, 1, 1) * (kt / (eta * eta)) / abs(sr.normal * wt);
        Rayo transmitido(sr.hitPoint, wt);
        L = L + fr.compMult(sr.mundo->pTracer->trace_ray(reflejado, sr.depth + 1)) * abs(sr.normal * wi);
        L = L + ft.compMult(sr.mundo->pTracer->trace_ray(transmitido, sr.depth + 1)) * abs(sr.normal * wt);
    }
    return L;
}
