# client

import socket


def Main():
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    host = '127.0.0.1'
    port = 5090

    message = input('-> ')
    while message != 'q':
        s.sendto(message.encode('utf-8'), (host, port))
        data, addr = s.recvfrom(1024)
        print('Received from server: ' + data.decode('utf-8'))
        message = input('-> ')


if __name__ == '__main__':
    Main()
