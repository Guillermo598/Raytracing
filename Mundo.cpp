#include "Mundo.h"

#include "LuzEsfera.h"

void Mundo::mostrarPixel(int fil, int col, Vector3D &raw_color) {
    Vector3D mapped_color;
    mapped_color = max_to_one(raw_color);
    int x = col;
    int y = pv.vres - fil - 1;
    //int y = 200 - fil - 1;

    (*pImg)(x,y,0) = (BYTE)(mapped_color.x * 255);
    (*pImg)(x,y,1) = (BYTE)(mapped_color.y * 255);
    (*pImg)(x,y,2) = (BYTE)(mapped_color.z * 255);
}

void Mundo::testImg() {
    pImg = new CImg<BYTE>(200, 300, 1, 3);
    CImgDisplay dis_img((*pImg), "test");

    (*pImg)(1,1,0,0) = (BYTE)(0.5 * 255);
    (*pImg)(1,1,0,1) = (BYTE)(1 * 255);
    (*pImg)(1,1,0,2) = (BYTE)(1 * 255);

    dis_img.render((*pImg));
    dis_img.paint();

    while (!dis_img.is_closed()) {
        dis_img.wait();
    }

}

ShadeRec Mundo::hitObjetos(const Rayo &rayo) {
    ShadeRec sr(this);
    double t;

    Vector3D normal;
    Vector3D localHitPoint;

    double tmin = 1.0E10;
    int	numObjetos = objetos.size();

    for (int i= 0; i < numObjetos; i++) {
        if (objetos[i]->hit(rayo, t, sr) && t < tmin) {
            tmin = t;
            sr.hit_objeto = true;
            sr.pMaterial = objetos[i]->pMaterial;
            sr.hitPoint = rayo.o + rayo.d * t;
            normal = sr.normal;
            localHitPoint = sr.localHitPoint;
        }
    }

    if (sr.hit_objeto) {
        sr.t = tmin;
        sr.normal = normal;
        sr.localHitPoint = localHitPoint;
    }

    return sr;
}

void Mundo::addLuzEsfera(LuzEsfera *pLuzEsfera) {
    addObjeto(pLuzEsfera->pEsfera);
    addLuz(pLuzEsfera->pLuz);
    //for (auto& luz : pLuzEsfera->luces) addLuz(luz);
}
