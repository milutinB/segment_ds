#include <iostream>
#include "src/LeafDataAVL.h"
#include "src/FirstLayerNode.h"
#include <vector>
#include "src/SegmentDS.h"
#include <stdlib.h> 
#include <unordered_set>
#include <math.h>

#define PI 3.141592653589793238462643383279502884197169

int main() {
    // auto avl_tree = new LeafDataAVL<AbstractNode<int>>();

    // std::vector<int> integers{436, 1234523, 252345,32545,2345235,23452,23452,4324,23234,12341,65745,3452,67856,432534,756,2432354,413,78567,25234,8756,43523,8678,
    // 436, 1234523, 252345,32545,2345235,23452,23452,4324,23234,12341,65745,3452,67856,432534,756,2432354,413,78567,25234,8756,43523,8678};

    // std::vector<AVLTest::TestNode*> nodes;

    // for (auto n: integers)
    //     nodes.push_back(new AVLTest::TestNode(n));

    // for (auto node: nodes) {
    //     avl_tree->insert(node);
    //     avl_tree->post_order(avl_tree->get_root());
    //     std::cout << "end traversal\n";
    // }

    // avl_tree->post_order(avl_tree->get_root());
    srand (12345);

    auto segs = std::vector<SegmentDS::Segment*>();

    auto x_coords = std::unordered_set<double>();
    auto y_coords = std::unordered_set<double>();

    // for (int i = 0; i < 10000; ++i) {
    //     auto x1 = rand() % 1000000;
        
    //     while (x_coords.find(x1) != x_coords.end())
    //         x1 = rand() % 1000000;
        
    //     x_coords.emplace(x1);

    //     auto x2 = rand() % 1000000;
    //     while (x_coords.find(x2) != x_coords.end())
    //         x2 = rand() % 1000000;

    //     x_coords.emplace(x2);

    //     auto y = rand() % 1000000;
    //     while (y_coords.find(y) != y_coords.end())
    //         y = rand() % 1000000;

    //     y_coords.emplace(y);

    //     double theta = PI / 4;

    //     segs.push_back(new Segment(x1*cos(theta) - y*sin(theta), x1*sin(theta) + y* cos(theta), 
    //     x2*cos(theta) - (y+0.0001)*sin(theta), x2*sin(theta) + (y+0.0001)* cos(theta)));
    // }

    // for (int i = 0; i < 1000000; ++i) {
    //     segs.push_back(new SegmentDS::Segment((i+1)*(0-(1/(i+1))), (i+1)*(0 + i), (i+1)*(1-1/(i+1)), (i+1)*(1 + i)));
    // }

    double eps = 0.001;

    segs.push_back(new SegmentDS::Segment(0, 0, 1, 1));
    segs.push_back(new SegmentDS::Segment(0.1, 0.1 + eps, 1.1, 1.1 + eps));
    segs.push_back(new SegmentDS::Segment(0.2, 0.2 + 2*eps, 1.2, 1.2 + 2*eps));
    segs.push_back(new SegmentDS::Segment(0.3, 0.3 + 3*eps, 1.3, 1.3 + 3*eps));
    segs.push_back(new SegmentDS::Segment(0.4, 0.4 + 4*eps, 1.4, 1.4 + 4*eps));
    segs.push_back(new SegmentDS::Segment(0.5, 0.5 + 5*eps, 1.5, 1.5 + 5*eps));
    segs.push_back(new SegmentDS::Segment(0.6, 0.6 + 6*eps, 1.6, 1.6 + 6*eps));
    segs.push_back(new SegmentDS::Segment(0.7, 0.7 + 7*eps, 1.7, 1.7 + 7*eps));
    segs.push_back(new SegmentDS::Segment(0.8, 0.8 + 8*eps, 1.8, 1.8 + 8*eps));

    auto query_seg = SegmentDS::Segment(0.05, -10, 0.05, 10);
    auto output = std::vector<SegmentDS::Segment>();
    std::cout << "start\n";
    auto segDS = SegmentDS::SegmentDS(segs);
    std::cout << "done\n";
    
    segDS.vertical_query(query_seg, output);
    
    segDS.count_segs();
//     std::cout << "segs in DS: " << SegmentDS::seg_count << std::endl;

//     std::cout << "size: " << segDS.node_count() << std::endl;
}