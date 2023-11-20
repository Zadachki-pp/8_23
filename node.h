

namespace node {
    struct Node {
        int data;
        Node *next;
    };
    void add(Node *root, int data);
    void add_back(Node *root, int data);
    void print(Node *root);
    void free(Node *root);
    bool is_sorted_asc(Node* root);
    bool is_sorted_desc(Node* root);
    bool is_sorted(Node* root);
    void delete_prime_numbers(Node* root);
    void duplicate_multiples_of_8(Node* root);
    void sort_by_numbers_sum(Node* root);
}