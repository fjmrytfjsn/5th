class Discount:
    def __init__(self, date, price):
        self.date = date 
        self.price = price

    def discount(self):
        if self.date=='Tue':
            self.price *= 0.7
        if self.price>=5000:
            self.price-=500
        print(self.price)


if __name__ == '__main__':
    tue1 = Discount('Tue', 8000)
    tue2 = Discount('Tue', 7000)
    thu1 = Discount('Thu', 8000)
    thu2 = Discount('Thu', 7000)
    tue1.discount()
    tue2.discount()
    thu1.discount()
    thu2.discount()
