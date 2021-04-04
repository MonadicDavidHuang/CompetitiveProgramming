import string  # noqa: F401
import random  # noqa: F401
import os


def write():
    # random.randint(0, 114514 + 1) # (0, 114514]

    # random.choice(string.ascii_letters[:24])

    # random.shuffle([1, 1, 4, 5, 1, 4])

    # ' '.join([1, 1, 4, 5, 1, 4])

    fst = ""

    snd = ""

    last = fst + "\n" + snd + "\n"

    with open("./Input.txt", "w") as f:
        f.write(last)


for loop in range(100):
    write()
    my = os.popen("./Solve.out < Input.txt").read()
    ac = os.popen("./Solve0.out < Input.txt").read()

    if not (my == ac):
        print("found!")
        break
