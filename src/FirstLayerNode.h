#pragma once

#include "FirstLayerNode.h"
#include "ElmInt.h"
#include "LeafDataAVL.h"
#include "SecondLayerNode.h"

namespace SegmentDS {
    class FirstLayerNode {

        private:

            FirstLayerNode* left;
            FirstLayerNode* right;
            FirstLayerNode* parent;
            ElmInt key;
            int height;
            ElmInt union_interval;
            LeafDataAVL<SecondLayerNode> second_layer_structure;

        public:

            inline static int count = 0;

            void set_union_interval(ElmInt interval);
            
            ElmInt& get_union_interval();

            ~FirstLayerNode();

            FirstLayerNode();

            FirstLayerNode(ElmInt _key);

            void insert_segment(Segment* seg);

            ElmInt& get_key();

            void set_key(ElmInt _key);

            FirstLayerNode* get_left();

            FirstLayerNode* get_right();

            FirstLayerNode* get_parent();

            void set_parent(FirstLayerNode* other);

            void set_left(FirstLayerNode* other);

            void set_right(FirstLayerNode* other);

            void copy_data(FirstLayerNode* other);

            int get_height();

            void update_height();

            int get_bf();

            void vertical_query(Segment query_seg, std::vector<Segment>& output);

            void count_segs();
        };
}