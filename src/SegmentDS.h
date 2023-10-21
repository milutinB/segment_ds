#pragma once

#include "Segment.h"
#include "LeafDataAVL.h"
#include "FirstLayerNode.h"
#include <vector>

namespace SegmentDS {
    class SegmentDS {
        private:
            LeafDataAVL<FirstLayerNode> first_layer_structure;

            void insert_segment(Segment* seg, FirstLayerNode* node);

            void combine_intervals(FirstLayerNode* node);

        public:
            int node_count();

            SegmentDS(std::vector<Segment*> segments);

            void vertical_query(Segment query_seg, std::vector<Segment>& output);

            void count_segs();

            // ~SegmentDS();
    };

}