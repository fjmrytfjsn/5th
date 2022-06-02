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