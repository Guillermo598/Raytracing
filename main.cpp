#include <iostream>

#include "Mundo.h"
#include "Geometria/Esfera.h"
#include "Geometria/Plano.h"
#include "Geometria/Cilindro.h"
#include "Geometria/Caja.h"
#include "Materiales/Matte.h"
#include "Materiales/Phong.h"

void escena1();
void escena2();

int main() {
    escena2();
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
    auto pPhongAzul = new Phong(0.25, 0.6, 0.2, 5, Vector3D(0, 0, 1));
    auto pPhongVerde = new Phong(0.25, 0.6, 0.2, 5, Vector3D(0, 1, 0));
    auto pPhongBlan = new Phong(0.25, 0.6, 0.2, 5, Vector3D(1, 1, 1));

    auto pEsfera1 = new Esfera(Vector3D(0, 20, 0), 15);
    pEsfera1->setMaterial(pPhongBlan);

    auto pPlano = new Plano(Vector3D(0, -20, 0), Vector3D(0, 1, 0));
    pPlano->setMaterial(pPhongBlan);

    //auto pEsfera2 = new Esfera(Vector3D(-20, 20, 0), 15);
    //pEsfera2->setMaterial(pPhongAzul);

    auto pLuz1 = new LuzPunto(Vector3D(0, 100, 25));
    auto pLuz2 = new LuzPunto(Vector3D(-25, 100, -25));
    auto pLuz3 = new LuzPunto(Vector3D(25, 100, -25));
    pLuz1->set_color(Vector3D(1,0,0));
    pLuz2->set_color(Vector3D(0,1,0));
    pLuz3->set_color(Vector3D(0,0,1));
    pLuz1->sombras = true;
    pLuz2->sombras = true;
    pLuz3->sombras = true;
    m.addLuz(pLuz1);
    m.addLuz(pLuz2);
    m.addLuz(pLuz3);

    auto pLuz = new LuzPunto(Vector3D(0, 400, 400));
    m.addLuz(pLuz);

    m.addObjeto(pPlano);
    m.addObjeto(pEsfera1);
    //m.addObjeto(pEsfera2);

    auto pCamara = new Camara();
    pCamara->setEye(0, 300, 300);
    pCamara->setLookat(0, 0, 0);
    pCamara->calcularUVW();
    m.pCamara = pCamara;

    m.pCamara->renderizarEscena(m);

}

void escena2(){
    Mundo m;

    m.pv.ojo.set(0, 0, 400);
    m.pv.dist = 100;

    m.pv.setHres(230);
    m.pv.setVres(230);
    m.pv.setTamPixel(0.5);
    m.pTracer = new Tracer(&m);

    auto pPhongRojo = new Phong(0.25, 0.6, 0.2, 5, Vector3D(1, 0, 0));
    auto pPhongAzul = new Phong(0.25, 0.6, 0.2, 5, Vector3D(0, 0, 1));
    auto pPhongVerde = new Phong(0.25, 0.6, 0.2, 5, Vector3D(0, 1, 0));
    auto pPhongBlan = new Phong(0.25, 0.6, 0.2, 5, Vector3D(1, 1, 1));

    auto frasco = new Cilindro(Vector3D(0, 0, 0), 40, 20);
    frasco->setMaterial(pPhongRojo);

    auto piso = new Plano(Vector3D(0, 0, 0), Vector3D(0, 1, 0));
    piso->setMaterial(pPhongBlan);

    for (int i = 0; i < 3; ++i) {
        auto ffly = new LuzPunto(Vector3D((rand()%20) - 10, rand()%40, (rand()%20) - 10));
        ffly->set_color(Vector3D(1,1,0));
        m.addLuz(ffly);
    }

    auto pLuz = new LuzPunto(Vector3D(0, 400, 400));
    m.addLuz(pLuz);

    m.addObjeto(piso);
    m.addObjeto(frasco);

    auto pCamara = new Camara();
    pCamara->setEye(0, 100, 400);
    pCamara->setLookat(0, 0, -50);
    pCamara->calcularUVW();
    m.pCamara = pCamara;

    m.pCamara->renderizarEscena(m);

}
