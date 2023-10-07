#pragma once

#include "Segment.h"
#include <stdexcept>

enum INTERVAL_TYPE { CO, OC, OO, CC };

namespace SegmentDS {
    class ElmInt {

        private:
            double left;
            double right;
            INTERVAL_TYPE type;

        public:

            ElmInt();

            ElmInt(double l, double r, INTERVAL_TYPE t);

            double get_left();
            
            double get_right();

            INTERVAL_TYPE get_type();

            bool operator>(ElmInt other);

            bool is_covered(Segment seg);

            bool intersects(Segment seg);

            bool contains(double qx);

            ElmInt const operator+(ElmInt& other);
    };
}