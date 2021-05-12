#include "Esfera.h"
#include "../ShadeRec.h"

bool Esfera::hit(const Rayo &rayo, double &tmin, ShadeRec &sr) const {
    double kEpsilon = 0.005;

    double 		t;
    Vector3D 	temp 	= rayo.o - centro;
    double 		a 		= rayo.d * rayo.d;
    double 		b 		= temp * rayo.d * 2.0;
    double 		c 		= temp * temp - radio * radio;
    double 		disc	= b * b - 4.0 * a * c;

    if (disc < 0.0)
        return false;
    else {
        double e = sqrt(disc);
        double denom = 2.0 * a;
        t = (-b - e) / denom;    // smaller root

        if (t > kEpsilon) {
            tmin = t;
            sr.normal = (temp + rayo.d * t) / radio;
            sr.localHitPoint = rayo.o + rayo.d * t;
            return true;
        }

        t = (-b + e) / denom;    // larger root

        if (t > kEpsilon) {
            tmin = t;
            sr.normal 	 = (temp + rayo.d * t) / radio;
            sr.localHitPoint = rayo.o + rayo.d * t;
            return true;
        }
    }

    return false;
}

bool Esfera::hit_sombra(const Rayo &rayo, double &tmin) const {
    double kEpsilon = 0.005;

    double 		t;
    Vector3D 	temp 	= rayo.o - centro;
    double 		a 		= rayo.d * rayo.d;
    double 		b 		= temp * rayo.d * 2.0;
    double 		c 		= temp * temp - radio * radio;
    double 		disc	= b * b - 4.0 * a * c;

    if (disc < 0.0)
        return false;
    else {
        double e = sqrt(disc);
        double denom = 2.0 * a;
        t = (-b - e) / denom;    // smaller root

        if (t > kEpsilon) {
            tmin = t;
            return true;
        }

        t = (-b + e) / denom;    // larger root

        if (t > kEpsilon) {
            tmin = t;
            return true;
        }
    }

    return false;
}
