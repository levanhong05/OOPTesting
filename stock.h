#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>

#include "product.h"

using namespace std;

class Stock
{
public:
    Stock();

    void input();

    Product *product() const;
    void setProduct(Product *product);

    int numProduct() const;
    void setNumProduct(int numProduct);

    string productName() const;
    void setProductName(const string &productName);

private:
    Product *_product;
    int _numProduct;
    string _productName;
};

#endif // STOCK_H
