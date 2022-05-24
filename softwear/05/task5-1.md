# Task5-1

## モジュール強度

今回のユースケースではプログラムの作成をほとんど行わないため、過去に作成したプログラムから例を挙げる。

```python:travel.py
class Car:
    def __init__(self, velocity, time):
        self.velocity = velocity
        self.time = time

    def drive(self):
        distance = self.calc_distance()
        print(f'{distance} drived')

    def calc_distance(self):
        return self.velocity*self.time

class AirPlane:
    def __init__(self, velocity, time):
        self.velocity = velocity
        self.time = time

    def fly(self):
        distance = self.velocity*self.time
        print(f'{distance} flew')

if __name__ == '__main__':
    car = Car(60, 4)
    car.drive()
    airplane = AirPlane(200, 1)
    airplane.fly()

```

これは、自動車および飛行機の移動距離を計算、出力するプログラムである。

calc_distanceでは距離の計算のみを行っている（6.機能的強度）のに対して、flyでは、飛行機の飛行距離を出力する際に実行される計算、出力の機能がまとめられている（4.手順的強度）。
