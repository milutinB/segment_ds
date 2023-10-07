#pragma once 

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

            double x1();

            double y1();
            
            double x2();
            
            double y2();
    };
}