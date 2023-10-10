class PaymentProcessor:
    def process_payment(self, amount):
        pass

class CreditCardPaymentProcessor(PaymentProcessor):
    def process_payment(self, amount):
        pass
        # Implement credit card payment logic

class PayPalPaymentProcessor(PaymentProcessor):
    def process_payment(self, amount):
        pass
        # Implement PayPal payment logic
