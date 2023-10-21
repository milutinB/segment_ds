#include <iostream>
#include <vector>
#include "src/SegmentDS.h"

int main() {
    auto s1 = SegmentDS::Segment(1, 0, 5, 0);
    auto s2 = SegmentDS::Segment(0, 1, 3, 1);
    auto s3 = SegmentDS::Segment(2, 3, 6, 3);

    auto query_seg = SegmentDS::Segment(1.5, 4, 1.5, -1);
    
    std::vector<SegmentDS::Segment> segs = {s1, s2, s3};
    
    auto data_structure = SegmentDS::SegmentDS(segs);

    std::vector<SegmentDS::Segment> output = {};

    data_structure.vertical_query(query_seg, output);

    for (auto seg: output)
        std::cout << seg << std::endl;
}