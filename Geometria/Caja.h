#ifndef UNTITLED_CAJA_H
#define UNTITLED_CAJA_H

#include "Objeto.h"
#include "../Utils/Vector3D.h"
#include "../Utils/Rayo.h"

class Caja : public Objeto {
public:
    double xi, xf;
    double yi, yf;
    double zi, zf;

    Caja(double _xi, double _xf, double _yi, double _yf, double _zi, double _zf);

    virtual bool hit(const Rayo &rayo, double &tmin, ShadeRec &sr) const;
    virtual bool hit_sombra(const Rayo &rayo, double &tmin) const;
    virtual void move(const Vector3D& v);
};


#endif //UNTITLED_CAJA_H
