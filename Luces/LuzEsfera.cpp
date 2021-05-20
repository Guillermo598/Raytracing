#include "LuzEsfera.h"


LuzEsfera::LuzEsfera(const Vector3D& centro, double radio, const Vector3D& color) {
    pEsfera = new Esfera(centro, radio);

    auto mirror = new Reflective();
    mirror->ka = 0.25;
    mirror->kd = 0.5;
    mirror->c = Vector3D(color);
    mirror->ks = 0.15;
    mirror->exp = 100;
    mirror->kr = 0.75;
    mirror->cr = Vector3D(1,1,1);

    pEsfera->setMaterial(mirror);
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            for (int k = -1; k < 2; ++k) {
                auto luz = new LuzPunto(centro + (Vector3D(i,j,k) * (radio + 0.1)));
                luz->sombras = false;
                luces.push_back(luz);
            }
        }
    }
}

void LuzEsfera::move(const Vector3D& v) const {
    pEsfera->move(v);
    for (auto& luz : luces)
        luz->posicion = luz->posicion + v;
}
