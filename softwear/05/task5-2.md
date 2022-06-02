# Task5-2

## モジュール結合度

今回のユースケースではプログラムの作成をほとんど行わないため、過去に作成したプログラムから例を挙げる。

```python:area.py
def triangle():
    height = 2
    base = 5
    return height*bace/2

def rectangle(height, width):
    return height*width

def main():
    print(triangle())
    print(rectangle(2, 5))

main()
```

これらは、三角形および四角形の面積を出力するプログラムである。

mainとtriangleは