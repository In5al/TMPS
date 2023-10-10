class Product:
    def __init__(self, name, description, price, stock_quantity):
        self.name = name
        self.description = description
        self.price = price
        self.stock_quantity = stock_quantity

class ProductManager:
    def add_product(self, product):
        pass

    def remove_product(self, product):
        pass

class ProductFactory:
    def create_product(self, name, description, price, stock_quantity):
        return Product(name, description, price, stock_quantity)

# Usage
factory = ProductFactory()
product1 = factory.create_product("Diamond Ring", "Exquisite diamond ring", 2500.0, 10)
product2 = factory.create_product("Gold Necklace", "Elegant gold necklace", 1200.0, 20)
