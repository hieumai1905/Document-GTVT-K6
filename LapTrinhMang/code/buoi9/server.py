# server
import socket


def Main():
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s.bind(('127.0.0.1', 5090))
    print('Server Started.')
    while True:
        data, addr = s.recvfrom(1024)
        print(data.decode('utf-8'))
        message = input('-> ')
        s.sendto(message.encode('utf-8'), addr)


if __name__ == '__main__':
    Main()
