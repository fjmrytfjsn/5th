class Message:
    def __init__(self, temperature):
        self.temperature = temperature

    def create_message(self):
        if self.temperature < 23.0:
            return '寒い'
        elif self.temperature < 25.0:
            return '快適'
        else:
            return '暑い'


if __name__ == '__main__':
    eq1 = Message(20.3)
    eq2 = Message(24.2)
    eq3 = Message(28.3)
    bdy1 = Message(22.9)
    bdy2 = Message(23.0)
    bdy3 = Message(24.9)
    bdy4 = Message(25.0)

    print(eq1.create_message())
    print(eq2.create_message())
    print(eq3.create_message())
    print(bdy1.create_message())
    print(bdy2.create_message())
    print(bdy3.create_message())
    print(bdy4.create_message())
