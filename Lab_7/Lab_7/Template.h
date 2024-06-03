#pragma once
#include <vector>
#include <stdexcept>

template<typename T>
class TreeNode {
public:
    T data;
    std::vector<TreeNode<T>*> children;

    TreeNode(T data) : data(data) {}
};

template<typename T>
class Tree {
public:
    TreeNode<T>* root;

    Tree() : root(nullptr) {}

    void add_child(TreeNode<T>* parent, T data) {
        TreeNode<T>* new_node = new TreeNode<T>(data);
        if (parent == nullptr) {
            if (root == nullptr) {
                root = new_node;
            }
            else {
                throw std::invalid_argument("Tree already has a root.");
            }
        }
        else {
            parent->children.push_back(new_node);
        }
    }

    TreeNode<T>* get_node(TreeNode<T>* parent, int index = 0) {
        if (parent == nullptr) {
            return root;
        }
        if (index < 0 || index >= parent->children.size()) {
            return nullptr;
        }
        return parent->children[index];
    }

    int node_count(TreeNode<T>* node) {
        if (node == nullptr) {
            return 0;
        }
        int count = 1;
        for (TreeNode<T>* child : node->children) {
            count += node_count(child);
        }
        return count;
    }
};
