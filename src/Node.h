#pragma once
#include "Segment.h"
#include <algorithm>

namespace SegmentDS {
    template <class KeyType>
    class Node {
        protected:
            Node<KeyType>* left;
            Node<KeyType>* right;
            Node<KeyType>* parent;
            KeyType key;
            int height = 1;

        public:
            KeyType& get_key() {
                return key;
            }

            void set_key(KeyType _key) {
                key = _key;
            }

            /**
             * @brief Recursively performs a vertical segment query in the subtree rooted at the
             * calling node. Segments found to intersect the query are pushed onto the output vector
             * whose reference is passed to subsequent recursive calls. 
             * 
             * @param query_seg 
             * @param output 
             */
            virtual void vertical_query(Segment& query_seg, std::vector<Segment>& output) = 0;

            /**
             * @brief Returns the heigh of the subtree rooted at the calling node
             * 
             * @return int 
             */
            int get_height() {
                return height;
            }

            void set_height(int h) {
                height = h;
            }

            /**
             * @brief Assigns the correct height to the calling node.
             * It is assumed that the heights of both children are correct
             * 
             * @return * void 
             */
            void update_height() {
                if (left == nullptr && right == nullptr)
                    return;
                if (left == nullptr && right != nullptr)
                    height = right->get_height() + 1;
                else if (right == nullptr && left != nullptr)
                    height = left->get_height() + 1;
                else
                    height = std::max(right->get_height(), left->get_height()) + 1;
            }

            /**
             * @brief Returns the balance factor of the calling node, i.e.,
             * the difference in hieght of the node's left and right subtrees.
             * It is assumed the heights of both children are correct.
             * @return int 
             */
            int get_bf() {
                if (left == nullptr && right == nullptr)
                    return 0;

                if (left == nullptr && right != nullptr)
                    return right->get_height();

                if (left != nullptr && right == nullptr)
                    return -left->get_height();

                return right->get_height() - left->get_height();
            }

            virtual ~Node() {};
    };
}
