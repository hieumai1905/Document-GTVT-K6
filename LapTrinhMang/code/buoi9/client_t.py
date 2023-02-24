# client

import socket


def Main():
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    host = '127.0.0.1'
    port = 5091
    message = input('-> ')
    while True:
        s.sendto(message.encode('utf-8'), (host, port))
        if message == 'bye':
            break
        data, addr = s.recvfrom(1024)
        data = data.decode('utf-8')
        print(f'Received from server: {data}')
        if data == 'bye':
            break
        message = input('-> ')
    s.close()

if __name__ == '__main__':
    Main()
