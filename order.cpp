#include "order.hpp"

using namespace std;

void OrderBook::add_buy_order(const RegularOrder& order) {
    //Risk Check function

    // Check if the order already exists
    auto it = buy_orders.find(order.price);
    if (it == buy_orders.end()) {
        // If not, create a new entry
        Value value;
        value.head = new Orders{nullptr, nullptr, order};
        value.tail = value.head;
        buy_orders[order.price] = value;
    } else {
        // If it exists, add the order to the linked list in FIFO style
        Orders* new_order = new Orders{it -> second.tail, nullptr, order};
        it -> second.tail -> prev = new_order;
        it -> second.tail = new_order;
    }
}

void OrderBook::del_order(RegularOrder* in_order, RegularOrder* out_order) {
    if (in_order -> quantity < out_order -> quantity) {
        out_order -> quantity = out_order -> quantity - in_order -> quantity;
        delete in_order;
    }
    else if (in_order -> quantity == out_order -> quantity) {
        delete out_order;
        delete in_order;
    }
    else {
        in_order -> quantity = in_order -> quantity - out_order -> quantity;
        if (out_order -> prev != nullptr) {
            RegularOrder* new_order = out_order -> prev;
            delete out_order;
            // Update the head of the Value in the map so that it points to out_order -> prev
            del_order(in_order, new_order);
        }
    }
}

void OrderBook::match_buy_order(const RegularOrder& order) {
    auto it = sell_orders.find(order.price);
    if (it != sell_orders.end()) {
        double diff = order.quantity - it -> second.head -> order.quantity;
        if (diff < 0) {
            it -> second.head -> order.quantity -= order.quantity
        }
        else if (diff == 0) {
            delete 
        }
    }
}