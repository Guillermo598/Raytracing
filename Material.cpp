#include "Material.h"

Vector3D Material::shade(ShadeRec &sr) {
    Vector3D wo = sr.rayo.d * (-1);
    Vector3D temp = ca * ka;
    Vector3D L = Vector3D(temp.x * 1,temp.y * 1,temp.z * 1); // luz ambiente default

    for (auto& luz : sr.mundo->luces) {
        Vector3D wi = luz->get_direccion(sr);
        double nwi = sr.normal * wi;
        if (nwi > 0.0)
            L = L + (((cd * kd * 0.3183098861837906715) * luz->L(sr)) * nwi);
    }
    return L;
}