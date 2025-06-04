#pragma once

#include <cstdint>
#include <vector>
#include <map>

using namespace std;

struct RegularOrder {
    bool type; // Is it a buy or sell order?
    int order_id;
    int customer_id;
    double quantity;
    uint64_t timestamp;
    int64_t price;
    RegularOrder* next;
    RegularOrder* prev;
};

struct Value {
    RegularOrder* head;
    RegularOrder* tail;
};