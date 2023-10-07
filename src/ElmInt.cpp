#include "ElmInt.h"

namespace SegmentDS {
    ElmInt::ElmInt() {
        left = 0;
        right = 0;
        type = CC;
    }

    ElmInt::ElmInt(double l, double r, INTERVAL_TYPE t) {
        left = l;
        right = r;
        type = t;
    }

    double ElmInt::get_left() { return left; }
    double ElmInt::get_right() { return right; }
    INTERVAL_TYPE ElmInt::get_type() { return type; }


    bool ElmInt::operator>(ElmInt other){
        return left >= other.get_right();
    }

    bool ElmInt::is_covered(Segment seg) {
        return seg.x1() <= left && seg.x2() >= right;
    }

    bool ElmInt::intersects(Segment seg) {
        return is_covered(seg) || ((seg.x1() >= left && seg.x1() <= right)
        || (seg.x2() >= left && seg.x2() <= right));
    }

    bool ElmInt::contains(double qx) {
        switch (type) {
            case CC: {
                return qx >= left && qx <= right;
                break;
            }
            case OC: {
                return qx > left && qx <= right;
                break;
            }
            case CO: {
                return qx >= left && qx < right;
                break;
            }
            case OO: {
                return qx > left && qx < right;
                break;
            }
        }
    }


    ElmInt const ElmInt::operator+(ElmInt& other) {
        if (!(other > *this))
            throw std::logic_error(
                "the left operand should be left of the right operand"
            );
        
        INTERVAL_TYPE new_type;

        auto o_type = other.get_type();

        if (type == OO || type == OC) {
            if (o_type == OC || o_type == CC) {
                new_type = OC;
            } else {
                new_type = OO;
            }
        }
        else if (type == CO || type == CC) {
            if (o_type == CO || o_type == OO) {
                new_type = CO;
            } else {
                new_type = CC;
            }
        }

        return ElmInt(left, other.get_right(), new_type);
    }
}