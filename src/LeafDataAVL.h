#pragma once
#include <iostream>
#include "node_utils.h"

namespace SegmentDS {
    /*
    * A generic implemntation of an AVL tree
    * which stores data in leaves
    * 
    * The class NodeType must implement the following functions:
    * 
    * NodeType* get_right()
    * void set_right(NodeType* _right)
    * NodeType* get_left()
    * void set_right(NodeType* _right)
    * NodeType* get_parent()
    * void set_parent(NodeType* parent)
    * 
    * void copy_data(NodeType* other) copies the children 
    * and parent pointers from other as well as any internal
    * data required for the comp function
    *
    * The comp function should return 1 if the key of the first
    * argument is strictly bigger than that of the second arugument
    * and -1 otherwise.
    *
    */
    template <class NodeType>
    class LeafDataAVL {
        private:
            NodeType* root=nullptr;

            void ascend(NodeType* node) {
                if (abs(get_bf<NodeType>(node)) >= 2)
                    repair(node);

                update_height<NodeType>(node);
                if (node->get_parent() != nullptr)
                    ascend(node->get_parent());
            }

            void repair(NodeType* node) {
                auto left = node->get_left();
                auto right = node->get_right();

                if (left->get_height() > right->get_height()) {
                    if (get_bf<NodeType>(left) > 0)
                        rotate_LeftRight(node, left);
                    else
                        rotate_Right(node, left);
                } else {
                    if (get_bf<NodeType>(right) < 0)
                        rotate_RightLeft(node, right);
                    else
                        rotate_Left(node, right);
                }
            }

            void rotate_Left(NodeType* X, NodeType* Z) {
                auto old_X_parent = X->get_parent();

                auto t23 = Z->get_left();
                X->set_right(t23);
                Z->set_left(X);

                if (X == root) {
                    root = Z;
                    Z->set_parent(nullptr);
                }
                else {
                    if (old_X_parent->get_right() == X)
                        old_X_parent->set_right(Z);
                    else
                        old_X_parent->set_left(Z);
                }
            }


            void rotate_Right(NodeType* X, NodeType* Z) {
                auto old_X_parent = X->get_parent();

                auto t23 = Z->get_right();
                X->set_left(t23);
                Z->set_right(X);

                if (X == root) {
                    root = Z;
                    Z->set_parent(nullptr);
                }
                else {
                    if (old_X_parent->get_right() == X)
                        old_X_parent->set_right(Z);
                    else
                        old_X_parent->set_left(Z);
                }
            }

            void rotate_RightLeft(NodeType* X, NodeType* Z) {
                auto old_X_parent = X->get_parent();

                auto Y = Z->get_left();
                auto t3 = Y->get_right();
                Z->set_left(t3);
                Y->set_right(Z);

                auto t2 = Y->get_left();
                X->set_right(t2);
                Y->set_left(X);

                update_height<NodeType>(Z);
                update_height<NodeType>(X);

                if (X == root) {
                    root = Y;
                    Y->set_parent(nullptr);
                }
                else {
                    if (old_X_parent->get_right() == X)
                        old_X_parent->set_right(Y);
                    else
                        old_X_parent->set_left(Y);
                }
            }

            void rotate_LeftRight(NodeType* X, NodeType* Z) {
                auto old_X_parent = X->get_parent();

                auto Y = Z->get_right();
                auto t3 = Y->get_left();
                Z->set_right(t3);
                Y->set_left(Z);
                auto t2 = Y->get_right();
                X->set_left(t2);
                Y->set_right(X);

                update_height<NodeType>(Z);
                update_height<NodeType>(X);

                if (X == root) {
                    root = Y;
                    Y->set_parent(nullptr);
                }
                else {
                    if (old_X_parent->get_right() == X)
                        old_X_parent->set_right(Y);
                    else
                        old_X_parent->set_left(Y);
                }
            }

            NodeType* find_leaf(NodeType* query_node, NodeType* root_of_search) {
                auto right_key = root_of_search->get_key();
                if (query_node->get_key() > right_key) {
                // if (comp(query_node, root_of_search) == 1) {
                    if (root_of_search->get_right() == nullptr)
                        return root_of_search;
                    else
                        return find_leaf(query_node, root_of_search->get_right());
                } else {
                    if (root_of_search->get_left() == nullptr)
                        return root_of_search;
                    else
                        return find_leaf(query_node, root_of_search->get_left());
                }     
            }

        public:
            ~LeafDataAVL() {
                if (root != nullptr)
                    delete root;
            }

            void insert(NodeType* node) {
                if (root == nullptr) {
                    root = node;
                    return;
                }

                auto leaf = find_leaf(node, root);

                auto new_node = new NodeType();
                new_node->copy_data(leaf);
                if (leaf != root &&
                    leaf == leaf->get_parent()->get_right())
                        leaf->get_parent()->set_right(new_node);
                else if (leaf != root)
                    leaf->get_parent()->set_left(new_node);
                
                new_node->set_key(node->get_key());

                auto right_key = leaf->get_key();
                if (node->get_key() > right_key) {
                    new_node->set_right(node);
                    new_node->set_left(leaf);
                } else {
                    new_node->set_right(leaf);
                    new_node->set_left(node);
                }

                if (root == leaf)
                    root = new_node;

                ascend(new_node);
            };

            NodeType* get_root() { return root; }

            void post_order(NodeType* node) {
                if (node->get_left() == nullptr && node->get_right() == nullptr) {
                    // std::cout << node->get_key() << std::endl;
                    return;
                }
                if (node->get_left() != nullptr)
                    post_order(node->get_left());
                if (node->get_right() != nullptr)
                    post_order(node->get_right());
            }
    };
}