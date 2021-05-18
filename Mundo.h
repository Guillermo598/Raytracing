#ifndef UNTITLED_MUNDO_H
#define UNTITLED_MUNDO_H

#include <vector>

class Objeto;
class LuzEsfera;

#include "Geometria/Objeto.h"
#include "Materiales/Material.h"
#include "Camara.h"
#include "PlanoVista.h"
#include "CImg.h"
#include "Luz.h"
#include "Tracer.h"
#include "LuzPunto.h"


using namespace cimg_library;
typedef unsigned char BYTE;

using namespace std;

class Mundo {
public:
    PlanoVista pv;
    CImg<BYTE> *pImg;
    Camara *pCamara;
    vector<Objeto*> objetos;
    vector<Luz*> luces;
    Tracer* pTracer;

    Mundo() {
        pImg = NULL;
        pCamara = NULL;
    }

    void testImg();

    void addObjeto(Objeto* pObjeto) { objetos.push_back(pObjeto); }

    void addLuz(Luz* pLuz) { luces.push_back(pLuz); }

    void addLuzEsfera(LuzEsfera* pLuzEsfera);

    void mostrarPixel(int fil, int col, Vector3D &pixel_color);

    Vector3D max_to_one(Vector3D &c) {
        float max_value = max(c.x, max(c.y, c.z));
        if (max_value > 1.0)
            return (c / max_value);
        else
            return (c);
    }

    ShadeRec hitObjetos(const Rayo &rayo);

};


#endif //UNTITLED_MUNDO_H
