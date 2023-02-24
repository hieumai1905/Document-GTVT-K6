# server
import socket


def Main():
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s.bind(('127.0.0.1', 5091))
    print('Server Started.')
    while True:
        data, addr = s.recvfrom(1024)
        print(f'Address client: {addr}')
        data = data.decode('utf-8')
        print(f'Data: {data}')
        if data == 'bye':
            break
        message = input('-> ')
        s.sendto(message.encode('utf-8'), addr)
        if message == 'bye':
            break
    s.close()


if __name__ == '__main__':
    Main()
