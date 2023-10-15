#include <gtest/gtest.h>
#include "../src/SecondLayerNode.h"

namespace {


    SegmentDS::SecondLayerNode leaf;
    SegmentDS::Segment s = SegmentDS::Segment(1, 2, 3, 4);
    SegmentDS::ElmInt interval = SegmentDS::ElmInt(1.5, 2.5, SegmentDS::CC);
    SegmentDS::SecondLayerNode non_leaf = SegmentDS::SecondLayerNode(interval, s);


    TEST(SecondLayerTest, height) {
        // The height of a leaf should be 1
        EXPECT_EQ(1, leaf.get_height());
    }
}
