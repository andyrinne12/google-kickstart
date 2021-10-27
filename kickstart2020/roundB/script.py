import sys
import random
import string

sys.stdout = open('input.txt', "w")


def generate(num):
    print(1)
    print(num, random.randint(2, 100))
    for i in range(num):
        print(id_generator(1000000))


def id_generator(size=6, chars=string.ascii_uppercase):
    return ''.join(random.choice(chars) for _ in range(size))


generate(10)

sys.stdout.close()
