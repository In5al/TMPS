import Order 

class JewelryShop:
    def __init__(self, product_manager, cart_manager, payment_processor, shipping_service):
        self.product_manager = product_manager
        self.cart_manager = cart_manager
        self.payment_processor = payment_processor
        self.shipping_service = shipping_service

    def add_product(self, product):
        self.product_manager.add_product(product)

    def register_customer(self, customer):
        self.cart_manager.calculate_total_price(customer)

    def process_order(self, customer, cart):
        total_price = self.cart_manager.calculate_total_price(cart)
        if self.payment_processor.process_payment(total_price):
            order = Order(cart.items, total_price)
            self.shipping_service.ship_order(order, customer)
