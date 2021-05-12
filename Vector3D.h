#ifndef UNTITLED_VECTOR3D_H
#define UNTITLED_VECTOR3D_H

#include <cmath>

class Vector3D {
public:
    double	x, y, z;

    Vector3D() { x = y = z = 0.0; }
    Vector3D(double vx, double vy, double  vz) { x = vx; y = vy; z = vz; }
    Vector3D(const Vector3D &v) { x = v.x; y = v.y; z = v.z; }

    void set(double vx, double vy, double  vz) { x = vx; y = vy; z = vz; }

    Vector3D operator-(const Vector3D &p) const { return Vector3D(x - p.x, y - p.y, z - p.z); }
    Vector3D operator-(const double a) const { return Vector3D(x - a, y - a, z - a); }

    Vector3D operator+(const Vector3D &p) const { return Vector3D(x + p.x, y + p.y, z + p.z); }
    Vector3D operator+(const double a) const { return Vector3D(x + a, y + a, z + a); }

    Vector3D operator*(const double a) const { return Vector3D(x * a, y * a, z * a); }
    double operator*(const Vector3D &p) const { return x * p.x + y * p.y + z * p.z; }

    Vector3D operator/(const double a) const { return Vector3D (x / a, y / a, z / a); }
    Vector3D operator^(const Vector3D &v) const { return Vector3D(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x); }

    void normalizar() {
        double tam = sqrt(x*x + y*y + z*z);
        x /= tam; y /= tam; z /= tam;
    }

    Vector3D& hat() {
        double tam = sqrt(x*x + y*y + z*z);
        x /= tam; y /= tam; z /= tam;
        return *this;
    }

    double distancia(const Vector3D& p) const {
        return (sqrt((x - p.x) * (x - p.x)
                + 	 (y - p.y) * (y - p.y)
                +	 (z - p.z) * (z - p.z) ));
    }

    Vector3D compMult(const Vector3D& c) const {
        return Vector3D(x * c.x, y * c.y, z * c.z);
    }

};


#endif //UNTITLED_VECTOR3D_H
