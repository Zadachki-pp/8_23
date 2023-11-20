#include <iostream>
#include <cmath>


bool _is_prime(int number);
int _get_numbers_sum(int number);


namespace node {
    struct Node {
        int data;
        Node* next;
    };

    void add(Node* root, int data) {
        Node* current = new Node;
        current->data = data;
        current->next = root->next;
        root->next = current;
    }

    void add_back(Node* root, int data) {
        Node* current = root;
        while (current->next != nullptr) {
            current = current->next;
        }

        add(current, data);
    }

    void print(Node* root) {
        Node* current = root->next;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void free(Node* root) {
        Node* current = root->next;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Убывание
    bool is_sorted_asc(Node* root) {
        Node* current = root->next;
        while (true) {
            if (current->next == nullptr) {
                break;
            }
            if (current->data < current->next->data) {
                return false;
            }

            current = current->next;
        }
        return true;
    }

    // Возрастание
    bool is_sorted_desc(Node* root) {
        Node* current = root->next;
        while (true) {
            if (current->next == nullptr) {
                break;
            }
            if (current->data > current->next->data) {
                return false;
            }

            current = current->next;
        }
        return true;
    }

    bool is_sorted(Node* root) {
        return is_sorted_asc(root) || is_sorted_desc(root);
    }

    void delete_prime_numbers(Node* root) {
        Node* current = root;
        Node* next = root->next;
        while (next != nullptr) {
            if (_is_prime(next->data)) {
                current->next = next->next;
                Node* tmp = next;
                next = next->next;
                delete tmp;
            } else {
                current = next;
                next = next->next;
            }
        }
    }

    void duplicate_multiples_of_8(Node* root) {
        Node* current = root->next;
        while (true) {
            if (current == nullptr) {
                break;
            }

            Node* next = current->next;
            if (current->data % 8 == 0) {
                Node* new_node = new Node();
                new_node->next = current->next;
                new_node->data = current->data;
                current->next = new_node;
            }

            current = next;
        }
    }

    int len(Node* root) {
        int result = 0;
        for (Node* i_current = root; i_current != nullptr; i_current=i_current->next) {
            result++;
        }
        return result-1;
    }

    void sort_by_numbers_sum(Node* root) {
        int len = node::len(root);
        for (int i = 0; i < len+1; i++) {
            for (Node* current = root; current->next->next != nullptr; current=current->next) {
                Node* node_1 = current->next;
                Node* node_2 = current->next->next;
                Node* last = node_2->next;
                if (
                    _get_numbers_sum(node_1->data) > _get_numbers_sum(node_2->data)
                ) {
                    node_1->next = last;
                    node_2->next = node_1;
                    current->next = node_2;
                }
            }
        }
    }
}

bool _is_prime(int number) {
    for (unsigned i = 2; i <= std::sqrt(number); i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}


int _get_numbers_sum(int number) {
    int result = 0;

    while (number != 0){
        int digit = number % 10;

        result += digit;

        number /= 10;
    }
    return result;
}