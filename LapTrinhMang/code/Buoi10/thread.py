import threading
from concurrent.futures import thread


def func_1(num):
    print(f'result 1:{num * num * num}')


def func_2(num):
    print(f'result 2:{num * num}')


def func_3(num):
    print(f'result 3:{num}')


if __name__ == '__main__':
    t1 = threading.Thread(target=func_1, args=(10,))
    t2 = threading.Thread(target=func_2, args=(10,))

    t1.start()
    t2.start()

    t1.join()
    t2.join()
    print('done')
