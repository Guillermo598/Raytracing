#include "Phong.h"

Phong::Phong() :
    ka(0),
    kd(0),
    ks(0),
    exp(0),
    ca(Vector3D(0, 0, 0)),
    cd(Vector3D(0, 0, 0)),
    cs(Vector3D(0, 0, 0)) {}

Phong::Phong(double ka, double kd, double ks, double e, Vector3D c) :
    ka(ka),
    kd(kd),
    ks(ks),
    exp(e),
    ca(c),
    cd(c),
    cs(c) {}


Vector3D Phong::shade(ShadeRec &sr) {
    Vector3D wo = sr.rayo.d * (-1);
    Vector3D temp = ca * ka;
    Vector3D L = temp.compMult(Vector3D(1,1,1)); // luz ambiente default

    for (auto& luz : sr.mundo->luces) {
        Vector3D wi = luz->get_direccion(sr);
        double nwi = sr.normal * wi;
        if (nwi > 0.0) {
            bool sombra = false;
            if (luz->sombras) {
                Rayo rayoSombra(sr.hitPoint, wi);
                sombra = luz->en_sombra(rayoSombra, sr);
            }
            if (!sombra) {
                Vector3D r(wi * (-1) + sr.normal * 2.0 * nwi);
                double rwo = r * wo;
                if (rwo > 0.0)
                    L = L + ((cd * kd * 0.3183098861837906715) + (cs * ks * pow(rwo, exp))).compMult(luz->L(sr)) * nwi;
                else
                    L = L + (cd * kd * 0.3183098861837906715).compMult(luz->L(sr)) * nwi;
            }
        }
    }
    return L;
}
