#pragma once
#include "Segment.h"
#include <algorithm>

namespace SegmentDS {

    /**
     * @brief Returns the balance factor of the argument node, i.e.,
     * the difference in hieght of the node's left and right subtrees.
     * It is assumed the heights of both children are correct.
     * @return int 
     */
    template <class NodeType>
    int get_bf(NodeType* node) {
        if (node->get_left() == nullptr && node->get_right() == nullptr)
            return 0;

        if (node->get_left() == nullptr && node->get_right() != nullptr)
            return node->get_right()->get_height();

        if (node->get_left() != nullptr && node->get_right() == nullptr)
            return -node->get_left()->get_height();

        return node->get_right()->get_height() 
        - node->get_left()->get_height();
    }

    /**
     * @brief Assigns the correct height to the argument node.
     * It is assumed that the heights of both children are correct
     * 
     * @return * void 
     */
    template <class NodeType>
    void update_height(NodeType* node) {
        if (node->get_left() == nullptr && node->get_right() == nullptr)
            return;
        if (node->get_left() == nullptr && node->get_right() != nullptr)
            node->set_height(node->get_right()->get_height() + 1);
        else if (node->get_right() == nullptr && node->get_left() != nullptr)
            node->set_height(node->get_left()->get_height() + 1);
        else
            node->set_height(std::max(
                node->get_right()->get_height(), 
                node->get_left()->get_height()
            ) + 1);
    }
}
