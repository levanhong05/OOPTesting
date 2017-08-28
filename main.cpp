#include <iostream>
#include <string>
#include <vector>

using namespace std;

static int numberCustomer = 0;
static int numberProduct = 0;
static int numberOrder = 0;

class Customer {
public:
    int id;
    string name;

    void input(int index = 0) {
        id = numberCustomer;

        numberCustomer++;

        cout << "Nhap ten khach hang thu " << index << ": ";
        cin >> name;
    }
};

class Product {
public:
    int id;
    string name;
    int price;

    void input(int index = 0) {
        id = numberProduct;

        numberProduct++;

        cout << "Nhap ten san pham thu " << index << ": ";
        cin >> name;

        cout << "Nhap gia san pham thu " << index << ": ";
        cin >> price;
    }
};

class Stocks {
public:
    Product *product;
    int numProduct;
    string productName;

    void input() {
        cout << "Nhap ten san pham: ";
        cin >> productName;

        cout << "Nhap so luong san pham: ";
        cin >> numProduct;
    }
};

class Order {
public:
    int id;
    int id_customer;
    vector<Stocks *> stocks;
};

class Store {
public:
    vector<Customer *> customers;

    vector<Stocks *> stocks;

    vector<Product *> products;

    vector<Order *> orders;

    void addCustomer(int index = 0) {
        Customer *customer = new Customer();
        bool existed = false;

        do {
            existed = false;
            customer->input(index);

            for(Customer *cus : customers) {
                if (cus->name == customer->name) {
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

    void addProduct(int index = 0) {
        Product *product = new Product();
        bool existed = false;

        do {
            existed = false;
            product->input(index);

            for(Product *pro : products) {
                if (pro->name == product->name) {
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

    void importStocks() {
        Stocks *stock = new Stocks();
        stock->input();

        for (Product *product : products) {
            if (product->name == stock->productName) {
                stock->product = product;
                break;
            }
        }

        bool existed = false;

        for (Stocks *s : stocks) {
            if (s->productName == stock->productName) {
                s->numProduct += stock->numProduct;

                existed = true;
                break;
            }
        }

        if (!existed) {
            stocks.push_back(stock);
        }
    }

    void createOrder() {
        Order *order = new Order();

        string name;
        int idCustomer = -1;

        do {
            cout << "Nhap ten khach mua hang: ";
            cin >> name;

            for (Customer *customer : customers) {
                if (customer->name == name) {
                    idCustomer = customer->id;
                    break;
                }
            }

            if (idCustomer == -1 || idCustomer >= numberCustomer) {
                cout << "Ma khach hang khong ton tai, vui long nhap lai." << endl;
            }
        } while (idCustomer >= numberCustomer);

        int soLuong;
        cout << "Nhap so luong loai hang hoa muon mua: ";
        cin >> soLuong;

        for (int i = 0; i < soLuong; i++) {
            Stocks *stock = new Stocks();

            bool productExisted = false;
            bool stockExisted = false;
            bool numOverflow = true;

            do {
                stock->input();

                for (Product *p : products) {
                    if (stock->productName == p->name) {
                        productExisted = true;
                        break;
                    }
                }

                for (Stocks *st : stocks) {
                    if (st->productName == stock->productName) {
                        stockExisted = true;

                        if (st->numProduct < stock->numProduct) {
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

            order->stocks.push_back(stock);
        }

        order->id = numberOrder;
        order->id_customer = idCustomer;

        orders.push_back(order);

        numberOrder++;
    }

    void showStock()
    {
        for (Stocks *stock : stocks) {
            cout << "Ten san pham: " << stock->product->name
                 << ", gia san pham: " << stock->product->price
                 << ", so luong san pham: " << stock->numProduct
                 << endl;
        }
    }

    vector<Order *> listCustomerOrdersByName(string name) {
        vector<Order *> orderByCustomer;

        int idCustomer = -1;

        for (Customer *customer : customers) {
            if (customer->name == name) {
                idCustomer = customer->id;
                break;
            }
        }

        if (idCustomer == -1) {
            cout << "Khach hang nay chua bao gio mua hang tai cua hang." << endl;
            return vector<Order*>();
        }

        for (Order *order : orders) {
            if (order->id_customer == idCustomer) {
                orderByCustomer.push_back(order);
            }
        }

        if (orderByCustomer.empty()) {
            cout << "Khach hang nay khong co don dat hang nao." << endl;
            return vector<Order*>();
        }

        return orderByCustomer;
    }
};

int main()
{
    Store *store = new Store();
    int numCustomer, numProduct;

    cout << "1. TAO DANH SACH KHACH HANG" << endl << endl;
    cout << "Nhap so luong khach hang: ";
    cin >> numCustomer;

    int index = 1;

    while (numCustomer > 0) {
        store->addCustomer(index);

        cout << endl;

        numCustomer--;

        index++;
    }
    cout << endl;

    //In danh sach khach hang
    cout << "-----IN DANH SACH KHACH HANG-----" << endl;
    for (Customer *customer : store->customers) {
        cout << "ID: " << customer->id
             << ", ten khach hang: " << customer->name
             << endl;
    }
    cout << endl;

    cout << "2. TAO DANH SACH SAN PHAM" << endl << endl;
    cout << "Nhap so luong san pham: ";
    cin >> numProduct;

    index = 1;
    while (numProduct > 0) {
        store->addProduct(index);

        cout << endl;

        numProduct--;

        index++;
    }

    cout << endl;

    //In danh sach san pham
    cout << "-----IN DANH SACH SAN PHAM-----" << endl;
    for (Product *product : store->products) {
        cout << "ID: " << product->id
             << ", ten san pham: " << product->name
             << ", gia san pham: " << product->price
             << endl;
    }
    cout << endl;

    cout << "3. THEM SAN PHAM VAO KHO" << endl << endl;
    string enter = "N";

    do {
        store->importStocks();

        cout << endl << "Nhan <Y> de tiep tuc, bat ky phim khac de thoat." << endl;
        cin >> enter;

        cout << endl;
    } while (enter == "Y" || enter == "y");
    cout << endl;

    cout << "4. IN DANH SACH SAN PHAM TRONG KHO" << endl;
    store->showStock();
    cout << endl;

    cout << "5. TAO DON DAT HANG" << endl << endl;
    store->createOrder();
    cout << endl;

    cout << "6. TRUY VAN DON DAT HANG CUA KHACH HANG THEO TEN" << endl << endl;
    string name;
    cout << "Nhap ten khach hang muon truy van: ";
    cin >> name;
    vector<Order *> orderByName = store->listCustomerOrdersByName(name);

    cout << "Order by " << name << endl;

    for (Order *order : orderByName) {
        cout << "ID: " << order->id << endl;
        for (Stocks *stock : order->stocks) {
            cout << "Ten san pham: " << stock->product->name << ", so luong: " << stock->numProduct << endl;
        }
        cout << endl;
    }

    return 0;
}
