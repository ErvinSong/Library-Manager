#include <iostream>

using namespace std;

// I want to create a C++ program that simulates an Order Booking System.

struct Order {
    int order_number;
    string customer;
    string type; // Is it a buy or sell order?
    double price;
    int quantity;
};

class OrderBook {
private:
    vector<Order> orders;

public:
    void add_order(const Order& order){
        orders.push_back(order);
    }

    void del_order(const Order& order){
        auto it = find_if(orders.begin(), orders.end(), [&](const Order& o) {
            return o.order_number == order.order_number;
        });
        if (it != orders.end()) {
            orders.erase(it);
        }
    }

};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}