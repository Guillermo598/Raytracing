#include "Caja.h"

Caja::Caja(double _xi, double _xf, double _yi, double _yf, double _zi, double _zf) :
    xi(_xi), xf(_xf), yi(_yi), yf(_yf), zi(_zi), zf(_zf) {

}

bool Caja::hit(const Rayo &rayo, double &tmin, ShadeRec &sr) const {
    double kEpsilon = 0.005;

    double a = 1.0 / rayo.d.x;
    double tx_min = ((a>=0?xi:xf) - rayo.o.x) * a;
    double tx_max = ((a>=0?xf:xi) - rayo.o.x) * a;

    double b = 1.0 / rayo.d.y;
    double ty_min = ((b>=0?yi:yf) - rayo.o.y) * b;
    double ty_max = ((b>=0?yf:yi) - rayo.o.y) * b;

    double c = 1.0 / rayo.d.z;
    double tz_min = ((c>=0?zi:zf) - rayo.o.z) * c;
    double tz_max = ((c>=0?zf:zi) - rayo.o.z) * c;

    double t0 = tx_min;
    if (ty_min > t0) t0 = ty_min;
    if (tz_min > t0) t0 = tz_min;

    double t1 = tx_max;
    if (ty_max < t1) t1 = ty_max;
    if (tz_max < t1) t1 = tz_max;

    return (t0 < t1 && t1 > kEpsilon);
}

bool Caja::hit_sombra(const Rayo &rayo, double &tmin) const {
    return false;
}
