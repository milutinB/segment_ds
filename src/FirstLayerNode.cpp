#include "FirstLayerNode.h"

namespace SegmentDS {
    void FirstLayerNode::set_union_interval(ElmInt interval) {
        union_interval = interval;
    };

    ElmInt& FirstLayerNode::get_union_interval() { return union_interval; }

    FirstLayerNode::~FirstLayerNode() {
        delete left;
        delete right;
    }

    FirstLayerNode::FirstLayerNode() {
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        height = 1;
        key = ElmInt(0, 0, CC);
        count++;    
        second_layer_structure = LeafDataAVL<SecondLayerNode>();
    }

    FirstLayerNode::FirstLayerNode(ElmInt _key) {
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        height = 1;
        key = _key;
        count++;
    }

    void FirstLayerNode::insert_segment(Segment& seg) {
        auto node = new SecondLayerNode(union_interval, seg);
        second_layer_structure.insert(node);
    }

    ElmInt& FirstLayerNode::get_key() {
        return key;
    }

    void FirstLayerNode::set_key(ElmInt _key) {
        key = _key;
    }

    int FirstLayerNode::get_height() {
        return height;
    }

    void FirstLayerNode::set_height(int h) {
        height = h;
    }

    FirstLayerNode* FirstLayerNode::get_left() {
        return left;
    }

    FirstLayerNode* FirstLayerNode::get_right() {
        return right;
    }

    FirstLayerNode* FirstLayerNode::get_parent() {
        return parent;
    }

    void FirstLayerNode::set_parent(FirstLayerNode* other) {
        parent = other;
    }

    void FirstLayerNode::set_left(FirstLayerNode* other) {
        left = other;
        if (other != nullptr)
            other->set_parent(this);
    }

    void FirstLayerNode::set_right(FirstLayerNode* other) {
        right = other;
        if (other != nullptr)
            other->set_parent(this);
    }

    void FirstLayerNode::copy_data(FirstLayerNode* other) {
        parent = other->get_parent();
        left = other->get_left();
        right = other->get_right();
        key = other->get_key();
        height = other->get_height();
    }

    void FirstLayerNode::vertical_query(Segment& query_seg, std::vector<Segment>& output) {
        if (union_interval.contains(query_seg.x1())) {
            if (second_layer_structure.get_root() != nullptr) {
                second_layer_structure.get_root()
                ->vertical_query(query_seg, output);
            }
        }
        if (left != nullptr && left->get_union_interval()
        .contains(query_seg.x1())) {
            left->vertical_query(query_seg, output);
        }

        if (right != nullptr && right->get_union_interval()
        .contains(query_seg.x1())) {
            right->vertical_query(query_seg, output);
        }
    }

    void FirstLayerNode::count_segs() {
        if (second_layer_structure.get_root() != nullptr) {
            // if (second_layer_structure.get_root()->get_height() > 5)
            //     std::cout << "interesting...\n";
            second_layer_structure.get_root()->count_segs();
        }

        if (left != nullptr)
            (left)->count_segs();
        if (right != nullptr)
            (right)->count_segs();
    }
}