# Task5-2

## モジュール結合度

今回のユースケースではプログラムの作成をほとんど行わないため、過去に作成したプログラムから例を挙げる。

```python:area.py
def triangle():
    return tri_height*tri_base/2

def rectangle(height, width):
    return height*width

def main():
    global tri_height
    global tri_base
    tri_height = 2
    tri_base = 5
    print(triangle())
    rec_height = 2
    rec_width = 5
    print(rectangle(rec_height, rec_width))

main()
```

これらは、三角形および長方形の面積を出力するプログラムである。

mainとtriangleは外部結合、mainとrectangleはスタンプ結合である。
