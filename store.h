#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <string>
#include <vector>

#include "customer.h"
#include "product.h"
#include "order.h"
#include "stock.h"

using namespace std;

class Store
{
public:
    Store();

    vector<Customer *> customers;

    vector<Stock *> stocks;

    vector<Product *> products;

    vector<Order *> orders;

    void addCustomer(int &numberCustomer, int index = 0);

    void addProduct(int &numberProduct, int index = 0);

    void importStocks();

    void createOrder(int &numberOrder, int numberCustomer);

    void showStock();

    vector<Order *> listCustomerOrdersByName(string name);
};

#endif // STORE_H
