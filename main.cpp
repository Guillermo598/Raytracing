#include <iostream>

#include "Mundo.h"
#include "Geometria/Esfera.h"
#include "Geometria/Plano.h"
#include "Geometria/Cilindro.h"
#include "Materiales/Matte.h"
#include "Materiales/Phong.h"
#include "Materiales/Transparent.h"
#include "LuzEsfera.h"
#include "Geometria/Disco.h"
#include <time.h>

void escena2();

int main() {
    escena2();
    return 0;
}

void escena2(){
    Mundo m;

    m.pv.ojo.set(0, 0, 400);
    m.pv.dist = 100;

    m.pv.setHres(230);
    m.pv.setVres(230);
    m.pv.setTamPixel(0.5);
    m.pTracer = new Tracer(&m);

    auto vidrio = new Transparent();
    vidrio->ks = 0.5;
    vidrio->exp = 70;
    vidrio->ior = 1.56;
    vidrio->kr = 0.1;
    vidrio->kt = 0.9;

    auto pMatteBlan = new Matte(0.9, 0.05, Vector3D(0.1, 0.1, 0.1));
    auto pPhongGris = new Phong(0.25, 0.6, 2, 5,  Vector3D(0.8, 0.8, 0.8));


    // Frasco cilindrico
    auto frasco = new Cilindro(Vector3D(0, 0, 0), 40, 20);
    frasco->setMaterial(vidrio);
    auto frasco_base = new Disco(Vector3D(0, 0.1, 0), Vector3D(0, 1, 0), 20);
    frasco_base->setMaterial(vidrio);
    auto frasco_tapa = new Disco(Vector3D(0, 41, 0), Vector3D(0, 1, 0), 21);
    frasco_tapa->setMaterial(pPhongGris);
    auto frasco_tapa_c = new Cilindro(Vector3D(0, 35, 0), 6, 21);
    frasco_tapa_c->setMaterial(pPhongGris);
    m.addObjeto(frasco);
    m.addObjeto(frasco_base);
    m.addObjeto(frasco_tapa);
    m.addObjeto(frasco_tapa_c);

    auto piso = new Plano(Vector3D(0, 0, 0), Vector3D(0, 1, 0));
    piso->setMaterial(pMatteBlan);
    m.addObjeto(piso);

    srand(time(nullptr));
    std::vector<LuzEsfera*> fflys;
    for (int i = 0; i < 5; ++i) {
        Vector3D rpos((rand()%20) - 10, (rand()%30) + 5, (rand()%20) - 10);
        auto ffly = new LuzEsfera(rpos, 1, Vector3D(1,1,0));
        fflys.push_back(ffly);
        m.addLuzEsfera(ffly);
    }

    auto pCamara = new Camara();
    pCamara->setEye(0, 75, 300);
    pCamara->setLookat(0, 0, -100);
    pCamara->calcularUVW();
    m.pCamara = pCamara;

    m.pCamara->renderizarEscena(m, 0);
    for (int i = 1; i < 30; ++i) {
        for (auto& ffly : fflys) {
            ffly->move(Vector3D(rand()%2?1:-1, rand()%2?1:-1, rand()%2?1:-1) * 0.25);
        }
        m.pCamara->renderizarEscena(m, i);
    }


}
