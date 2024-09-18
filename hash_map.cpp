#include "hash_map.h"

hash_map::hash_map(size_t capacity) {
    _size = 0;
    _capacity = capacity;
    _head[int(_capacity)];
}

hash_map::hash_map(const hash_map &other) {
    _size = 0;
    _capacity = 0;
    _head[int(_capacity)];

    for (int i = 0; i < int(_capacity);i++) {
        _head[i] = other._head[i];
    }
}

hash_map &hash_map::operator=(const hash_map &other) {
    hash_map temp = other;
    std::swap(_size,temp._size);
    std::swap(_head,temp._head);
    std::swap(_capacity,temp._capacity);

    return *this;
}

void hash_map::insert(int key, float value) {
    int index = key % int(_capacity);
    if (index < 0) { index *= -1;}
    _head[index].insert(key,value);
}

std::optional<float> hash_map::get_value(int key) const {
    for (int i = 0;i < int(_capacity);i++) {
        node *ptr = _head[i].head;
        while (ptr != NULL) {
            if (ptr->key == key){
                std::optional<float> val = ptr->value;
                return val;
            } 
            ptr = ptr->next;
        }
        i++;
    }
    return std::nullopt;
}

bool hash_map::remove(int key) {
    bool keyv = false;
    for (int i = 0;i < int(_capacity);i++) {
        keyv = _head[i].remove(key); 
    }
    return keyv;
}

size_t hash_map::get_size() const {
    return _size;
}

size_t hash_map::get_capacity() const {
    return _capacity;
}

void hash_map::get_all_keys(int *keys) {
    int j = 0;
    for (int i = 0;i < int(_capacity);i++) {
        node *ptr = _head[i].head;
        while (ptr != NULL) {
            keys[j] = ptr->key;
            ptr = ptr->next;
            j++;
        }
    }
}

void hash_map::get_bucket_sizes(size_t *buckets) {
    for (int i = 0;i < int(_capacity);i++) {
        buckets[i] = _head[i].get_size();
    }
}

