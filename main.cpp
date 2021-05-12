#include <iostream>

#include "Mundo.h"
#include "Geometria/Esfera.h"
#include "Geometria/Plano.h"
#include "Geometria/Cilindro.h"
#include "Geometria/Caja.h"
#include "Materiales/Matte.h"
#include "Materiales/Phong.h"

void escena1();

int main() {
    escena1();
    return 0;
}
void escena1(){
    Mundo m;

    m.pv.ojo.set(0, 0, 400);
    m.pv.dist = 100;

    m.pv.setHres(230);
    m.pv.setVres(230);
    m.pv.setTamPixel(0.5);
    m.pTracer = new Tracer(&m);

    auto pMatAzul = new Matte(0.25, 0.65, Vector3D(0, 0, 1));
    auto pMatVerde = new Matte(0.25, 0.65, Vector3D(0, 1, 0));
    auto pMatRojo = new Matte(0.25, 0.65, Vector3D(1, 0, 0));
    auto pMatBlan = new Matte(0.25, 0.65, Vector3D(1, 1, 1));

    auto pPhongRojo = new Phong(0.25, 0.6, 0.2, 5, Vector3D(1, 0, 0));

    auto pCilindroP = new Cilindro(Vector3D(20, -20, 0), 50, 15);
    pCilindroP->setMaterial(pPhongRojo);

    auto pPlano = new Plano(Vector3D(0, -20, 0), Vector3D(0, 1, 0));
    pPlano->setMaterial(pMatBlan);

    auto pCilindroM = new Cilindro(Vector3D(-20, -20, 0), 50, 15);
    pCilindroM->setMaterial(pMatRojo);

    auto pLuz1 = new LuzPunto(Vector3D(0, 0, 100));
    auto pLuz2 = new LuzPunto(Vector3D(0, 100, 0));
    m.addLuz(pLuz1);
    m.addLuz(pLuz2);

    //m.addObjeto(pPlano);
    m.addObjeto(pCilindroM);
    m.addObjeto(pCilindroP);

    auto pCamara = new Camara();
    pCamara->setEye(0, 100, 400);
    pCamara->setLookat(0, 0, 0);
    pCamara->calcularUVW();
    m.pCamara = pCamara;

    m.pCamara->renderizarEscena(m);

}
