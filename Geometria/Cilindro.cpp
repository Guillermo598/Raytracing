#include "Cilindro.h"

Cilindro::Cilindro(Vector3D c, double h, double r) : centro(c), altura(h), radio(r) {

}

bool Cilindro::hit(const Rayo &rayo, double &tmin, ShadeRec &sr) const {
    double kEpsilon = 0.005;

    double t;
    double a = rayo.d.x * rayo.d.x + rayo.d.z * rayo.d.z;
    double b = (rayo.d.x * (rayo.o.x - centro.x) + rayo.d.z * (rayo.o.z - centro.z)) * 2.0;
    double c =  (rayo.o.x - centro.x) * (rayo.o.x - centro.x) +
                (rayo.o.z - centro.z) * (rayo.o.z - centro.z) -
                (radio * radio);
    double disc	= b * b - 4.0 * a * c;

    if (disc < 0.0)
        return false;
    else {
        double e = sqrt(disc);
        double denom = 2.0 * a;
        t = (-b - e) / denom;    // smaller root

        if (t > kEpsilon) {
            double yhit = rayo.o.y + t * rayo.d.y;
            if (yhit >= centro.y && yhit <= centro.y + altura) {
                tmin = t;
                sr.normal = Vector3D((rayo.o.x + rayo.d.x * t) * (1/radio), 0.0, (rayo.o.z + rayo.d.z * t) * (1/radio));

                if (rayo.d * (-1) * sr.normal < 0.0)
                    sr.normal = sr.normal * (-1);

                sr.localHitPoint = rayo.o + rayo.d * t;

                return true;
            }
        }

        t = (-b + e) / denom;    // larger root

        if (t > kEpsilon) {
            double yhit = rayo.o.y + t * rayo.d.y;
            if (yhit >= centro.y && yhit <= centro.y + altura) {
                tmin = t;
                sr.normal = Vector3D((rayo.o.x + rayo.d.x * t) * (1/radio), 0.0, (rayo.o.z + rayo.d.z * t) * (1/radio));

                if (rayo.d * (-1) * sr.normal < 0.0)
                    sr.normal = sr.normal * (-1);

                sr.localHitPoint = rayo.o + rayo.d * t;

                return true;
            }
        }
    }

    return false;
}