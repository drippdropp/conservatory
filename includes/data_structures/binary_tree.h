#ifndef CONSERVATORY_INCLUDES_DATA_STRUCTURES_BINARY_TREE_H
#define CONSERVATORY_INCLUDES_DATA_STRUCTURES_BINARY_TREE_H

#include <iostream>
#include <type_traits>

template <typename K, typename T, class = typename std::enable_if<std::is_integral<K>::value>::type>
class BTNode {
public:
  K key;
  T value;

  BTNode<K,T> *left;
  BTNode<K,T> *right;

  BTNode(K _key, T _value) : key{_key}, value{_value} {}
};


template <typename K, typename T, class = typename std::enable_if<std::is_integral<K>::value>::type>
class BTree {
public:
  BTNode<K,T> *root = nullptr;

public: void add_node(K key, T data) {
    auto *node = new BTNode<K, T>(key, data);
    if (this->root == nullptr) {
      this->root = node;
    } else {
      auto *target_node = this->root;
      BTNode<K,T> *parent = nullptr;

      while (true) {
        parent = target_node;
        if (key < target_node->key) {
          target_node = target_node->left;
          if (target_node == nullptr) {
            parent->left = node;
            return;
          }
        } else {
          target_node = target_node->right;
          if (target_node == nullptr) {
            parent->right = node;
            return;
          }
        }
      }
    }
  }

public: BTNode<K,T> find_node(K key) {
    auto *target_node = root;
    while (target_node->key != key) {
      if (key < target_node->key) {
        target_node = target_node->left;
      } else {
        target_node = target_node->right;
      }
      if (target_node == nullptr) return nullptr;
    }
    auto output_node = *target_node;
    return output_node;
  }

public: bool remove(K key) {
    auto *target_node = root;
    auto *parent = root;

    bool is_left = true;
    while (target_node->key != key) {
      parent = target_node;
      if (key < target_node->key) {
        is_left = true;
        target_node = target_node->left;
      } else {
        is_left = false;
        target_node = target_node->right;
      }

      if (target_node == nullptr) return false;
    }

    if (target_node->left == nullptr && target_node->right == nullptr) {
      if (target_node == root) {
        root = nullptr;
      } else if (is_left) {
        parent->left_child = nullptr;
      } else {
        parent->right_child = nullptr;
      }
    } else if (target_node->right == nullptr) {
      if (target_node == root) {
        root = target_node->left;
      } else if (is_left) {
        parent->left = target_node->left;
      } else {
        parent->right = target_node->left;
      }
    } else if (target_node->left == nullptr) {
      if (target_node == root) {
        root = target_node->right;
      } else if (is_left) {
        parent->left = target_node->right;
      } else {
        parent->right = target_node->left;
      }
    } else {
      auto *swap_node = get_swap_node(target_node);
      if (target_node == root) {
        root = swap_node;
      } else if (is_left) {
        parent->left = swap_node;
      } else {
        parent->right = swap_node;
      }
      swap_node->left = target_node->left;
    }
    return true;
  }

private: BTNode<K,T> get_swap_node(BTNode<K,T> node) {
    return new BTNode<K,T>(node.key, node.value);
  }


public: void in_order_traverse_tree(BTNode<K,T> *target_node) {
    if (target_node != nullptr) {
      in_order_traverse_tree(target_node->left);
      std::cout << target_node << std::endl;
      in_order_traverse_tree(target_node->right);
    }
  }

public: void pre_order_traverse_tree(BTNode<K,T> *target_node) {
    if (target_node != nullptr) {
      std::cout << target_node << std::endl;
      pre_order_traverse_tree(target_node->left);
      pre_order_traverse_tree(target_node->right);
    }
  }

public: void post_order_traverse_tree(BTNode<K,T> *target_node) {
    if (target_node != nullptr) {
      post_order_traverse_tree(target_node->left);
      post_order_traverse_tree(target_node->right);
      std::cout << target_node << std::endl;
    }
  }
};

#endif
