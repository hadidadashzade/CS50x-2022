# TODO
n = 0


def main():
    try:
        while True:
            height = int(input("Height: "))
            if height > 0 and height < 9:
                break
    except ValueError:
        main()

    n = height

    for i in range(n):
        print(" " * (n - i - 1), end="")
        print("#" * (i + 1), end="")
        print("  ", end="")
        print("#" * (i + 1))
        

main()
