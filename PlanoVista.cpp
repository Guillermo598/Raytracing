#include "PlanoVista.h"

PlanoVista::PlanoVista() : ojo(0,0,200) {
    hres = 400;
    vres = 400;
    tamPixel = 1.0;
    numMuestras = 1;
    gamma = 1.0;
    invGamma = 1.0;
    zoom = 1.0;
    dist = 100;
}