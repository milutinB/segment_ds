#pragma once 
#include <ostream>

namespace SegmentDS {
    class Segment {
        private:
            double _x1;
            double _y1;
            double _x2;
            double _y2;

        public:
            bool real;
            
            Segment(double x1, double y1, double x2, double y2);

            Segment();

            double x1() const;

            double y1() const;
            
            double x2() const;
            
            double y2() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const Segment& seg);
}