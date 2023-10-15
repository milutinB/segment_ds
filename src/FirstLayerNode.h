#pragma once

#include "FirstLayerNode.h"
#include "ElmInt.h"
#include "LeafDataAVL.h"
#include "SecondLayerNode.h"

namespace SegmentDS {
    class FirstLayerNode : public Node<ElmInt> {
        private:
            ElmInt union_interval;
            LeafDataAVL<SecondLayerNode> second_layer_structure;

        public:
            inline static int count = 0;

            void set_union_interval(ElmInt interval);
            
            ElmInt& get_union_interval();

            ~FirstLayerNode() override;

            FirstLayerNode();

            FirstLayerNode(ElmInt _key);

            void insert_segment(Segment* seg);

            ElmInt& get_key();

            void set_key(ElmInt _key);

            FirstLayerNode* get_left();

            FirstLayerNode* get_right();

            FirstLayerNode* get_parent();

            void set_parent(Node<ElmInt>* other);

            void set_left(Node<ElmInt>* other);

            void set_right(Node<ElmInt>* other);

            void copy_data(Node<ElmInt>* other);

            void vertical_query(Segment& query_seg, std::vector<Segment>& output) override;

            void count_segs();
        };
}