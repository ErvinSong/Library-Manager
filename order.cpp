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
        // If it exists, add the order to the linked list
        Orders* new_order = new Orders{nullptr, it->second.tail, order};
        it->second.tail->next = new_order;
        it->second.tail = new_order;
    }
}