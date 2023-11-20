#include <iostream>
#include "node.h"


using namespace std;


int main() {
    auto root = new node::Node;
    root->next = nullptr;

    unsigned n;
    cin >> n;
    for (unsigned i = 0; i < n; i++) {
        int value;
        cin >> value;
        node::add_back(root, value);
    }
    if (!node::is_sorted(root)){
        node::delete_prime_numbers(root);
        node::duplicate_multiples_of_8(root);
    } else {
        node::sort_by_numbers_sum(root);
    }

    node::print(root);
    return 0;
}
