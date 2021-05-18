#include "LuzEsfera.h"


LuzEsfera::LuzEsfera(const Vector3D& centro, double radio, const Vector3D& color) {
    pEsfera = new Esfera(centro, radio);
    auto foco = new Transparent();
    foco->ks = 1;
    foco->exp = 2000;
    foco->ior = 1;
    foco->kr = 1;
    foco->kt = 1;
    foco->c = color;
    pEsfera->setMaterial(foco);
    pLuz = new LuzPunto(centro);
}

void LuzEsfera::move(const Vector3D& v) const {
    pEsfera->move(v);
    pLuz->posicion = pLuz->posicion + v;
}
