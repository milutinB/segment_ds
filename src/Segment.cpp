#include "Segment.h"

namespace SegmentDS {
    Segment::Segment(double x1, double y1,
        double x2, double y2) {
        _x1 = x1;
        _y1 = y1;
        _x2 = x2;
        _y2 = y2;

        if (_x1 > _x2) {
            _x1 = x2;
            _x2 = x1;
        }

        real = true;
    }

    Segment::Segment() {
        _x1 = 0;
        _x2 = 0;
        _y1 = 0;
        _y2 = 0;

        real = false;
    }

    double Segment::x1() { return _x1; }
    double Segment::y1() { return _y1; }
    double Segment::x2() { return _x2; }
    double Segment::y2() { return _y2; }
}