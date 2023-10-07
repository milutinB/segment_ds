#pragma once

#include <algorithm>
#include "src/AbstractNode.h"

namespace AVLTest {
    class TestNode: public AbstractNode<int> {

        private:

        public:
            TestNode() {
                AbstractNode<int>::left = nullptr;
                AbstractNode<int>::right = nullptr;
                AbstractNode<int>::parent = nullptr;
                AbstractNode<int>::key = 0;
                AbstractNode<int>::height = 1;
            };

            TestNode(int _key) {
                AbstractNode<int>::left = nullptr;
                AbstractNode<int>::right = nullptr;
                AbstractNode<int>::parent = nullptr;
                AbstractNode<int>::key = _key;
                AbstractNode<int>::height = 1;
            }
    };

}