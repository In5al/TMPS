class ProductBrowser:
    def browse_products(self, products):
        pass

class ProductViewer:
    def view_product(self, product):
        pass

class ProductPurchaser:
    def purchase_product(self, product, quantity):
        pass

class Customer:
    def __init__(self, name):
        self.name = name

class CustomerWithBrowse(ProductBrowser):
    def __init__(self, name):
        self.name = name

class CustomerWithView(ProductViewer):
    def __init__(self, name):
        self.name = name

class CustomerWithPurchase(ProductPurchaser):
    def __init__(self, name):
        self.name = name
