#pragma once

#include "LeafDataAVL.h"
#include "ElmInt.h"
#include "Segment.h"
#include <CGAL/Cartesian.h>
#include <CGAL/Line_2.h>
#include <CGAL/Segment_2.h>
#include <CGAL/Point_2.h>
#include "Node.h"

namespace SegmentDS {
    struct KeyStruct {
        double val;
        Segment seg;

        KeyStruct(double _val, Segment _seg) 
        : val(_val), seg(_seg) {}

        KeyStruct();

        bool operator>(KeyStruct& other);
    };

    class SecondLayerNode : public Node<KeyStruct> {

        private:
            Segment seg;
            ElmInt host_interval;

        public:
            inline static int count = 0;

            SecondLayerNode();

            SecondLayerNode(ElmInt _host_interval, Segment _seg);

            void set_key(KeyStruct _key);

            SecondLayerNode* get_left();

            SecondLayerNode* get_right();

            SecondLayerNode* get_parent();

            void set_parent(Node<KeyStruct>* other);

            void set_left(Node<KeyStruct>* other);

            void set_right(Node<KeyStruct>* other);

            /**
             * @brief copies member variables from other
             * 
             * @param other 
             */
            void copy_data(Node<KeyStruct>* other);

            void count_segs();
            
            void vertical_query(Segment& query_seg, std::vector<Segment>& output) override;

            ~SecondLayerNode() override;
    };
}