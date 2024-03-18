#ifndef SERVER_H
#define SERVER_H

#include "OrderBook/OrderBook.h"
#include "Orders/Order.h"
#include "Instrument/Instrument.h"
#include <vector>
#include <unordered_map>

using namespace std; // Add this line to bring the entire std namespace into scope

class Server {
private:
    OrderBook orderBook;
    unordered_map<string, vector<Order>> pendingOrders; // Map to store pending orders awaiting matching

public:
    void submitOrder(const Order& order);
    void cancelOrder(const string& orderId);
    void matchOrders();
    void printOrderBook() const;
};

#endif // SERVER_H
