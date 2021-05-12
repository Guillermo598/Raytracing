#include "Camara.h"
#include "PlanoVista.h"
#include "ShadeRec.h"

void Camara::calcularUVW() {
    w = ojo - lookat;
    w.normalizar();
    Vector3D up(0, 1, 0);
    u = up ^ w;
    u.normalizar();
    v = w ^ u;
}

Vector3D Camara::getDireccion(Vector3D p) {
    Vector3D tmp = v * p.y;
    Vector3D tmp2 = w * 500;
    Vector3D dir = u * p.x + tmp - tmp2;
    dir.normalizar();
    return dir;
}

void Camara::renderizarEscena(Mundo m) {
    PlanoVista	pv(m.pv);
    Rayo rayo;
    Vector3D pp;
    Vector3D color;
    int n = 1;
    int depth = 0;
    rayo.o = ojo;

    m.pImg = new CImg<BYTE>(pv.hres, pv.vres, 1, 3);
    CImgDisplay dis_img((*m.pImg), "", 3, false, true);

    int r, c, p = 0, q = 0;
    for (r = 0; r < pv.vres; r++) {
        for (c = 0; c < pv.hres; c++) {
            color.set(0,0,0);
            pp.x = pv.tamPixel * (c - 0.5 * pv.hres + (q + 0.5) );
            pp.y = pv.tamPixel * (r - 0.5 * pv.vres + (p + 0.5) );
            rayo.d = getDireccion(pp);

            color = color + m.pTracer->trace_ray(rayo, depth);

            m.mostrarPixel(r, c, color);
            dis_img.render((*m.pImg));
            dis_img.paint();
        }
    }
    while (!dis_img.is_closed()) {
        dis_img.wait();
    }
    m.pImg->save("../render.bmp");
}