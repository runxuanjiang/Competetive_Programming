#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

enum class Status{
    Empty,
    Filled,
    Ghost
};

//Hashes ints to ints
class HashTable{
public:

    struct Bucket{
        int key;
        int val;
        Status status = Status::Empty;
    };

    // HashTable() {
    //     // do nothing
    // }

    size_t size() const {
        return num_elements;
    }

    int& operator[] (const int& key) {
        if (num_elements >= buckets.size() / 2) {
            rehash_and_grow();
        }
        size_t k = std::hash<int>{}(key) % buckets.size();
        
        Bucket* avail = nullptr;
        for (size_t i = 0; i < buckets.size(); ++i) {
            size_t a = (k + i) % buckets.size();
            if ((buckets[a].status == Status::Ghost || buckets[a].status == Status::Empty) && !avail) {
                avail = &(buckets[a]);
            }
                    
            //insert
            if (buckets[a].status == Status::Empty) {
                avail->key = key;
                avail->status = Status::Filled;
                ++num_elements;
                return avail->val;
            }
            //found
            else if (buckets[a].status == Status::Filled && buckets[a].key == key) {
                return buckets[a].val;
            }
        }
        return buckets[0].val;
        
    }

    bool insert(const int &key, const int& val) {
        if (num_elements >= buckets.size() / 2) {
            rehash_and_grow();
        }

        size_t k = std::hash<int>{}(key) % buckets.size();

        Bucket* avail = nullptr;
        for (size_t i = 0; i < buckets.size(); ++i) {
            size_t a = (k + i) % buckets.size();
            if ((buckets[a].status == Status::Ghost || buckets[a].status == Status::Empty) && !avail) {
                avail = &(buckets[a]);
            }

            //insert
            if (buckets[a].status == Status::Empty) {
                avail->key = key;
                avail->status = Status::Filled;
                avail->val = val;
                ++num_elements;
                return true;
            }
            //found
            else if (buckets[a].status == Status::Filled && buckets[a].key == key) {
                return false;
            }
        }
        return false;
    }

    size_t erase(const int& key) {
        size_t k = std::hash<int>{}(key) % buckets.size();
        for (size_t i = 0; i < buckets.size(); ++i) {
            size_t a = (k + i) % buckets.size();

            //not found
            if (buckets[a].status == Status::Empty) {
                return 0;
            }
            //found
            else if (buckets[a].status == Status::Filled && buckets[a].key == key) {
                buckets[a].status = Status::Ghost;
                --num_elements;
                return 1;
            }
        }
        return 0;
    }

private:
    size_t num_elements = 0;
    std::vector<Bucket> buckets;

    void rehash_and_grow() {
        std::vector<Bucket> oldBuckets = buckets;
        std::vector<Bucket> newBuckets((num_elements + 1) * 4);
        buckets = newBuckets;
        num_elements = 0;

        for (auto bucket : oldBuckets) {
            if (bucket.status == Status::Filled) {
                insert(bucket.key, bucket.val);
            }
        }
    }
};
