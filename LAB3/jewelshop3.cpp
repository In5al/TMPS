#include <iostream>
#include <vector>
#include <memory>

// Singleton for Logging
class Logger {
public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void log(const std::string& message) {
        std::cout << message << std::endl;
    }

private:
    Logger() {}
};

// Builder Pattern for Product Creation
class JewelryItem {
public:
    JewelryItem(std::string name, double price) : name(name), price(price) {}
    std::string getName() const {
        return name;
    }
    double getPrice() const {
        return price;
    }

private:
    std::string name;
    double price;
};

class JewelryItemBuilder {
public:
    JewelryItemBuilder& setName(const std::string& name) {
        jewelryItemName = name;
        return *this;
    }

    JewelryItemBuilder& setPrice(double price) {
        jewelryItemPrice = price;
        return *this;
    }

    JewelryItem build() {
        return JewelryItem(jewelryItemName, jewelryItemPrice);
    }

private:
    std::string jewelryItemName;
    double jewelryItemPrice;
};

// Factory Method for Discounted Products
class DiscountedJewelryFactory {
public:
    virtual JewelryItem createDiscountedJewelryItem() = 0;
};

class PercentageDiscountedJewelryFactory : public DiscountedJewelryFactory {
public:
    PercentageDiscountedJewelryFactory(double discountPercentage) : discount(discountPercentage) {}

    JewelryItem createDiscountedJewelryItem() override {
        return JewelryItem("Discounted Jewelry Item", basePrice * (1 - discount));
    }

private:
    double discount;
    double basePrice = 100.0; // Default base price
};

// Decorator Pattern for adding additional features to JewelryItem
class JewelryItemDecorator : public JewelryItem {
public:
    JewelryItemDecorator(JewelryItem& item) : JewelryItem(item.getName(), item.getPrice()), item(item) {}

    std::string getName() const {
        return item.getName();
    }

    double getPrice() const {
        return item.getPrice();
    }

private:
    JewelryItem& item;
};

class GemstoneDecorator : public JewelryItemDecorator {
public:
    GemstoneDecorator(JewelryItem& item, std::string gemstone) : JewelryItemDecorator(item), gemstone(gemstone) {}

    std::string getName() const {
        return JewelryItemDecorator::getName() + " with " + gemstone;
    }

private:
    std::string gemstone;
};

// Adapter Pattern to make JewelryItem compatible with a legacy system
class LegacyItem {
public:
    LegacyItem(std::string description, double cost) : description(description), cost(cost) {}
    std::string getDescription() const {
        return description;
    }
    double getCost() const {
        return cost;
    }

private:
    std::string description;
    double cost;
};

class JewelryItemAdapter : public JewelryItem {
public:
    JewelryItemAdapter(LegacyItem legacyItem) : JewelryItem(legacyItem.getDescription(), legacyItem.getCost()) {}
};

// Composite Pattern to represent a collection of jewelry items
class JewelryCollection : public JewelryItem {
public:
    JewelryCollection(std::string name) : JewelryItem(name, 0.0) {}

    void addItem(std::shared_ptr<JewelryItem> item) {
        items.push_back(item);
    }

    double getPrice() const {
        double total = 0.0;
        for (const auto& item : items) {
            total += item->getPrice();
        }
        return total;
    }

private:
    std::vector<std::shared_ptr<JewelryItem>> items;
};

// Proxy Pattern for JewelryItem
class JewelryItemProxy : public JewelryItem {
public:
    JewelryItemProxy(std::string name, double price) : JewelryItem(name, price) {
        // You can add additional proxy logic here.
    }
};

int main() {
    // Singleton for Logging
    Logger& logger = Logger::getInstance();
    logger.log("This is a log message.");

    // Builder Pattern for Product Creation
    JewelryItemBuilder builder;
    JewelryItem normalRing = builder.setName("Normal Ring").setPrice(100.0).build();

    // Factory Method for Discounted Products
    PercentageDiscountedJewelryFactory factory(0.2); // 20% discount
    JewelryItem discountedRing = factory.createDiscountedJewelryItem();

    // Decorator Pattern to add gemstones
    JewelryItem diamondRing = GemstoneDecorator(normalRing, "Diamond");
    JewelryItem sapphireRing = GemstoneDecorator(discountedRing, "Sapphire");

    // Adapter Pattern
    LegacyItem legacyItem("Legacy Ring", 50.0);
    JewelryItemAdapter adaptedLegacyItem(legacyItem);

    // Composite Pattern
    JewelryCollection collection("Jewelry Collection");
    collection.addItem(std::make_shared<JewelryItem>(normalRing));
    collection.addItem(std::make_shared<JewelryItem>(discountedRing));
    collection.addItem(std::make_shared<JewelryItem>(diamondRing));
    collection.addItem(std::make_shared<JewelryItem>(sapphireRing));

    // Proxy Pattern
    JewelryItemProxy proxyRing("Proxy Ring", 200.0);

    std::vector<JewelryItem> products = {normalRing, discountedRing, diamondRing, sapphireRing, adaptedLegacyItem, collection, proxyRing};

    for (const JewelryItem& product : products) {
        std::cout << product.getName() << " - Original Price: $" << product.getPrice() << std::endl;
    }

    return 0;
}
