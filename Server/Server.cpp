#include "Server.h"
#include "RiskManagement/RiskManager.h"
#include "Logging/Logger.h"
#include <algorithm>

using namespace std; 

void Server::submitOrder(const Order& order) {
    if (RiskManager::checkRisk(order)) {
        // Check if the order can be matched immediately
        if (orderBook.matchOrder(order)) {
            Logger::log(Logger::INFO, "Order matched immediately: " + order.orderId);
        } else {
            // If not matched, add to pending orders
            pendingOrders[order.instrument.symbol].push_back(order);
            Logger::log(Logger::INFO, "Order added to pending orders: " + order.orderId);
        }
    } else {
        Logger::log(Logger::WARNING, "Order rejected due to risk management constraints: " + order.orderId);
    }
}

void Server::cancelOrder(const string& orderId) {
    // Check if the order is in the pending orders
    for (auto& pair : pendingOrders) {
        auto& orders = pair.second;
        auto it = find_if(orders.begin(), orders.end(), [&](const Order& order) {
            return order.orderId == orderId;
        });
        if (it != orders.end()) {
            orders.erase(it);
            Logger::log(Logger::INFO, "Order canceled: " + orderId);
            return;
        }
    }
    Logger::log(Logger::WARNING, "Order not found in pending orders: " + orderId);
}

void Server::matchOrders() {
    // Iterate through all pending orders and try to match them
    for (auto& pair : pendingOrders) {
        auto& symbol = pair.first;
        auto& orders = pair.second;
        for (auto& order : orders) {
            if (orderBook.matchOrder(order)) {
                Logger::log(Logger::INFO, "Order matched: " + order.orderId);
            }
        }
    }
}

void Server::printOrderBook() const {
    orderBook.printOrderBook();
}
