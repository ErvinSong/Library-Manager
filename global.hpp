#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include "order.hpp"  // for OrderBook

class OrderBook{
    public:
        void add_buy_order(const RegularOrder& order);
        void add_sell_order(const RegularOrder& order);
        void del_order(RegularOrder* in_order, RegularOrder* out_order);
    private:
        map<int64_t, Value> buy_orders;

};

extern OrderBook* global_order_book;  // Declare it here

#endif
