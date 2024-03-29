#include "SecondLayerNode.h"

namespace SegmentDS {
    using Kernel = CGAL::Cartesian<double>;
    using Point_2 = CGAL::Point_2<Kernel>;
    using Line_2 = CGAL::Line_2<Kernel>;
    using Segment_2 = CGAL::Line_2<Kernel>;

    KeyStruct::KeyStruct() {
        val = 0;
        seg = Segment();
    }

    bool KeyStruct::operator>(KeyStruct& other) {
        return val > other.val;
    }

    SecondLayerNode::SecondLayerNode() {
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        count++;
    }

    SecondLayerNode::~SecondLayerNode() {
        delete left;
        delete right;
    }

    SecondLayerNode::SecondLayerNode(ElmInt _host_interval, Segment _seg) {
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        seg = _seg;
        host_interval = _host_interval;
        Line_2 vertical_boundary = Line_2(Point_2(_host_interval.get_left(), 0), 
        Point_2(_host_interval.get_left(), 1));
        
        Line_2 seg_line = Line_2(
            Point_2(_seg.x1(), _seg.y1()), 
            Point_2(_seg.x2(), _seg.y2())
        );

        auto int_obj = CGAL::intersection(vertical_boundary, seg_line);
        key = KeyStruct(boost::get<Point_2>(*int_obj).y(), seg);

        count++;
    }

    void SecondLayerNode::set_key(KeyStruct _key) {
        key = _key;
    }

    KeyStruct SecondLayerNode::get_key() {
        return key;
    }

    int SecondLayerNode::get_height() {
        return height;
    }

    void SecondLayerNode::set_height(int h) {
        height = h;
    }

    SecondLayerNode* SecondLayerNode::get_left() {
        return left;
    }

    SecondLayerNode* SecondLayerNode::get_right() {
        return right;
    }

    SecondLayerNode* SecondLayerNode::get_parent() {
        return parent;
    }

    void SecondLayerNode::set_parent(SecondLayerNode* other) {
        parent = other;
    }

    void SecondLayerNode::set_left(SecondLayerNode* other) {
        left = other;
        if (other != nullptr)
            other->set_parent(this);
    }

    void SecondLayerNode::set_right(SecondLayerNode* other) {
        right = other;
        if (other != nullptr)
            other->set_parent(this);
    }

    void SecondLayerNode::copy_data(SecondLayerNode* other) {
        parent = other->get_parent();
        left = other->get_left();
        right = other->get_right();
        key = other->get_key();
        height = other->get_height();
    }

    void SecondLayerNode::count_segs() {
        if (left != nullptr)
            left->count_segs();
        if (right != nullptr)
            right->count_segs();
    }

    void SecondLayerNode::vertical_query(Segment& query_seg, std::vector<Segment>& output) {
        Line_2 line = Line_2(Point_2(key.seg.x1(), key.seg.y1()), 
        Point_2(key.seg.x2(), key.seg.y2()));

        if (left == nullptr && right == nullptr) {
            if (line.has_on_negative_side(Point_2(query_seg.x1(), query_seg.y1()))
            && line.has_on_positive_side(Point_2(query_seg.x2(), query_seg.y2()))) {
                output.push_back(key.seg);
            }
        } else {
            if (left != nullptr 
            && (line.has_on_negative_side(Point_2(query_seg.x1(), query_seg.y1())) ||
            line.has_on_negative_side(Point_2(query_seg.x2(), query_seg.y2())))) {
                left->vertical_query(query_seg, output);
            }
            if (right != nullptr 
            && (line.has_on_positive_side(Point_2(query_seg.x1(), query_seg.y1())) ||
            line.has_on_positive_side(Point_2(query_seg.x2(), query_seg.y2())))) {
                right->vertical_query(query_seg, output);
            }
        }
    }
}