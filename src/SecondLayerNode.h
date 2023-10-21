#pragma once

#include "LeafDataAVL.h"
#include "ElmInt.h"
#include "Segment.h"
#include <CGAL/Cartesian.h>
#include <CGAL/Line_2.h>
#include <CGAL/Segment_2.h>
#include <CGAL/Point_2.h>
// #include "Node.h"

namespace SegmentDS {
    struct KeyStruct {
        double val;
        Segment seg;

        KeyStruct(double _val, Segment _seg) 
        : val(_val), seg(_seg) {}

        KeyStruct();

        bool operator>(KeyStruct& other);
    };

    class SecondLayerNode {
        private:
            SecondLayerNode* left;
            SecondLayerNode* right;
            SecondLayerNode* parent;
            int height = 1;
            KeyStruct key;
            Segment seg;
            ElmInt host_interval;
            

        public:
            inline static int count = 0;

            SecondLayerNode();

            SecondLayerNode(ElmInt _host_interval, Segment _seg);

            void set_key(KeyStruct _key);

            KeyStruct get_key();

            void set_height(int h);

            int get_height();

            SecondLayerNode* get_left();

            SecondLayerNode* get_right();

            SecondLayerNode* get_parent();

            void set_parent(SecondLayerNode* other);

            void set_left(SecondLayerNode* other);

            void set_right(SecondLayerNode* other);

            /**
             * @brief copies member variables from other
             * 
             * @param other 
             */
            void copy_data(SecondLayerNode* other);

            void count_segs();
            
            void vertical_query(Segment& query_seg, std::vector<Segment>& output);

            ~SecondLayerNode();
    };
}