#ifndef UNTITLED_RAYO_H
#define UNTITLED_RAYO_H

#include "Vector3D.h"

class Rayo {
public:
    Vector3D o, d;
    Rayo() {}
    Rayo(Vector3D &ori, Vector3D &dir) : o(ori), d(dir) {}

};


#endif //UNTITLED_RAYO_H
