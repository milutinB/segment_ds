#include <gtest/gtest.h>
#include "../src/node_utils.h"
#include "../src/Segment.h"

namespace {
    class MockNode {
        private:
            int height = 1;
            MockNode* left;
            MockNode* right;
            MockNode* parent;
        public:
            void set_height(int h) {height = h;}
            void set_left(MockNode* other) {left = other;}
            void set_parent(MockNode* other) {parent = other;}
            void set_right(MockNode* other) {right = other;}
            int get_height() {return height;}
            MockNode* get_left() {return dynamic_cast<MockNode*>(left);}
            MockNode* get_right() {return dynamic_cast<MockNode*>(right);}
            MockNode* get_parent() {return dynamic_cast<MockNode*>(parent);}
            void vertical_query(SegmentDS::Segment& query_seg, std::vector<SegmentDS::Segment>& output) {return;}
    };


    TEST(NodeTest, update_height) {
        auto a = MockNode();
        auto b = MockNode();
        auto c = MockNode();
        a.set_left(&b);
        a.set_right(&c);

        // test height before update is 1
        EXPECT_EQ(1, a.get_height());

        SegmentDS::update_height<MockNode>(&a);

        // test height after update is 2
        EXPECT_EQ(2, a.get_height());

        // add a few more descendants
        auto d = MockNode();
        auto e = MockNode();
        auto f = MockNode();
        b.set_left(&d);
        d.set_left(&e);
        e.set_left(&f);

        // test height still 2 before updates...
        EXPECT_EQ(2, a.get_height());

        SegmentDS::update_height<MockNode>(&f);
        SegmentDS::update_height<MockNode>(&e);
        SegmentDS::update_height<MockNode>(&d);
        SegmentDS::update_height<MockNode>(&b);
        SegmentDS::update_height<MockNode>(&a);

        // test height of all updated nodes is correct
        EXPECT_EQ(1, f.get_height());
        EXPECT_EQ(2, e.get_height());
        EXPECT_EQ(3, d.get_height());
        EXPECT_EQ(4, b.get_height());
        EXPECT_EQ(5, a.get_height());
    }

    TEST(NodeTest, balance_factor) {
        auto a = MockNode();
        auto b = MockNode();
        auto c = MockNode();
        auto d = MockNode();
        auto e = MockNode();
        auto f = MockNode();
        auto g = MockNode();

        /* 
        *   nodes to be arranged in the following tree:
        *
        *               a
        *              / \
        *             b   c
        *            / \
        *           e   f
        *          / 
        *         g
        */
       
        a.set_left(&b);
        a.set_right(&c);
        b.set_left(&e);
        b.set_right(&f);
        e.set_left(&g);

        g.set_height(1);
        e.set_height(2);
        b.set_height(3);
        f.set_height(1);
        a.set_height(4);
        c.set_height(1);

        // test that the balance factor of leaves is 0
        EXPECT_EQ(0, SegmentDS::get_bf<MockNode>(&g));
        EXPECT_EQ(0, SegmentDS::get_bf<MockNode>(&f));
        EXPECT_EQ(0, SegmentDS::get_bf<MockNode>(&c));

        // test the balance factor of b is -1
        EXPECT_EQ(-1, SegmentDS::get_bf<MockNode>(&b));
        
        // test the balance factor of a is -2
        EXPECT_EQ(-2, SegmentDS::get_bf<MockNode>(&a));
    }
}