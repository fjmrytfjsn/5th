# Task5-2

## モジュール結合度

今回のユースケースではプログラムの作成をほとんど行わないため、過去に作成したプログラムから例を挙げる。

```python:density.py
import random

class Car:
    @classmethod
    def drive(self, distance):
        print(f'{distance} drived')   


class AirPlane:
    @classmethod
    def fly(self, distance):
        print(f'{distance} flew')


def is_car():
    return random.randint(0, 1)

if ( is_car()  ):
    my_car = Car()
    my_car.drive(200)
else:
    my_plane = AirPlane()
    my_plane.fly(200)
```

これは、自動車および飛行機の飛行距離を出力するプログラムである。
