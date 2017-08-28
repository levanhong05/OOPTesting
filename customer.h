#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

using namespace std;

class Customer {
public:
    explicit Customer();

    void input(int id, int index = 0);

    int id() const;
    void setId(int id);

    string name() const;
    void setName(const string &name);

private:
        int _id;
        string _name;
};

#endif // CUSTOMER_H
