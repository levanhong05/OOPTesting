#include "store.h"

Store::Store()
{
}

void Store::addCustomer(int &numberCustomer, int index)
{
    Customer *customer = new Customer();
    bool existed = false;

    do {
        existed = false;
        customer->input(numberCustomer, index);

        for (Customer *cus : customers) {
            if (cus->name() == customer->name()) {
                existed = true;
                cout << "Khach hang da ton tai, vui long nhap khach hang khac." << endl;
                break;
            }
        }

        if (!existed) {
            customers.push_back(customer);
        }
    } while (existed);
}

void Store::addProduct(int &numberProduct, int index)
{
    Product *product = new Product();
    bool existed = false;

    do {
        existed = false;
        product->input(numberProduct, index);

        for (Product *pro : products) {
            if (pro->name() == product->name()) {
                existed = true;
                cout << "San pham da ton tai, vui long nhap san pham khac." << endl;
                break;
            }
        }

        if (!existed) {
            products.push_back(product);
        }
    } while (existed);
}

void Store::importStocks()
{
    Stock *stock = new Stock();
    stock->input();

    for (Product *product : products) {
        if (product->name() == stock->productName()) {
            stock->setProduct(product);
            break;
        }
    }

    bool existed = false;

    for (Stock *s : stocks) {
        if (s->productName() == stock->productName()) {
            s->setNumProduct(s->numProduct() + stock->numProduct());
            existed = true;
            break;
        }
    }

    if (!existed) {
        stocks.push_back(stock);
    }
}

void Store::createOrder(int &numberOrder, int numberCustomer)
{
    Order *order = new Order();
    string name;
    int idCustomer = -1;

    do {
        cout << "Nhap ten khach mua hang: ";
        cin >> name;

        for (Customer *customer : customers) {
            if (customer->name() == name) {
                idCustomer = customer->id();
                break;
            }
        }

        if (idCustomer == -1 || idCustomer >= numberCustomer) {
            cout << "Ma khach hang khong ton tai, vui long nhap lai." << endl;
        }
    } while (idCustomer == -1 || idCustomer >= numberCustomer);

    int soLuong;
    cout << "Nhap so luong loai hang hoa muon mua: ";
    cin >> soLuong;

    string enter = "";

    do {
        Stock *stock = new Stock();
        bool productExisted = false;
        bool stockExisted = false;
        bool numOverflow = false;

        do {
            stock->input();

            for (Product *p : products) {
                if (stock->productName() == p->name()) {
                    productExisted = true;
                    break;
                }
            }

            for (Stock *st : stocks) {
                if (st->productName() == stock->productName()) {
                    stockExisted = true;

                    if (st->numProduct() < stock->numProduct()) {
                        numOverflow = true;
                    }

                    break;
                }
            }

            if (!productExisted) {
                cout << "San pham khong ton tai, vui long nhap lai." << endl;
            } else if (!stockExisted) {
                cout << "San pham chua co trong kho, vui long nhap lai." << endl;
            } else if (numOverflow) {
                cout << "So luong san pham trong kho khong du, vui long nhap lai." << endl;
            }
        } while (!productExisted || !stockExisted || numOverflow);

        order->addStock(stock);

        cout << endl << "Nhan <F> de hoan tat, bat ky phim khac de tiep tuc mua hang." << endl;
        cin >> enter;

        cout << endl;
    } while (enter != "F" && enter != "f");

    order->setId(numberOrder);
    order->setIdCustomer(idCustomer);

    orders.push_back(order);

    numberOrder++;
}

void Store::showStock()
{
    for (Stock *stock : stocks) {
        cout << "Ten san pham: " << stock->product()->name()
             << ", gia san pham: " << stock->product()->price()
             << ", so luong san pham: " << stock->numProduct()
             << endl;
    }
}

vector<Order *> Store::listCustomerOrdersByName(string name)
{
    vector<Order *> orderByCustomer;
    int idCustomer = -1;

    for (Customer *customer : customers) {
        if (customer->name() == name) {
            idCustomer = customer->id();
            break;
        }
    }

    if (idCustomer == -1) {
        cout << "Khach hang nay chua bao gio mua hang tai cua hang." << endl;
        return vector<Order *>();
    }

    for (Order *order : orders) {
        if (order->idCustomer() == idCustomer) {
            orderByCustomer.push_back(order);
        }
    }

    if (orderByCustomer.empty()) {
        cout << "Khach hang nay khong co don dat hang nao." << endl;
        return vector<Order *>();
    }

    return orderByCustomer;
}
