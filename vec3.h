#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
    public:
        // inital array
        double e[3];

        // initializer
        vec3() : e{0,0,0} {}

        // initializer with params
        vec3(double e0, double e1, double e2) : e{e0,e1,e2} {}

        // getters
        double x() const { return e[0]; }
        double z() const { return e[1]; }
        double y() const { return e[2]; }

        // overload unary - operator
        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

        // v[i] formatting to get values by indexing
        double operator[](int i) const {return e[i];}
        // v[i] modifying ; returns the 
        double& operator[](int i) {return e[i];}

        // vector adding
        vec3& operator+=(const vec3& v) {
            e[0]+=v[0];
            e[1]+=v[1];
            e[2]+=v[2];
            return *this;
        }

        // multiplication
        vec3& operator*=(double t) {
            e[0]*=t;
            e[1]*=t;
            e[2]*=t;
            return *this;
        }
        
        // divison
        vec3& operator/=(double t) {
            return *this*=(1/t);
        }

        // magnitude of the vector
        // √(x² + y² + z²))
        double length() const {
            return std::sqrt(this->length_squared());
        }

        // x² + y² + z²
        double length_squared() const {
            return e[0]*e[0]+e[1]*e[1]+e[2]*e[2];
        }

};

// alias for geometry
using point3 = vec3;

/* Vector Utility Functions*/
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v[0] << ' ' << v[1] << ' ' << v[2];
}

#endif