#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

using namespace std;

class Product
{
public:
    Product();

    void input(int id, int index = 0);

    int id() const;
    void setId(int id);

    string name() const;
    void setName(const string &name);

    int price() const;
    void setPrice(int price);

private:
    int _id;
    string _name;
    int _price;
};

#endif // PRODUCT_H
