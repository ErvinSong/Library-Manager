#pragma once

#include <cstdint>
#include <vector>
#include <map>

using namespace std;

struct RegularOrder {
    bool type; // Is it a buy or sell order?
    int order_id;
    int customer_id;
    int quantity;
    uint64_t timestamp;
    int64_t price;
};

struct Orders {
    Orders* next;
    Orders* prev;
    RegularOrder order;
};

struct Value {
    Orders* head;
    Orders* tail;
};


class OrderBook{
    public:
        void add_buy_order(const RegularOrder& order);
        void add_sell_order(const RegularOrder& order);
        void del_order(const RegularOrder& order);
    private:
        map<int64_t, Value> buy_orders;

}