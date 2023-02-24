import socket
import sys

if __name__ == '__main__':
    try:
        sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM, proto=0, fileno=None)
    except socket.error as e:
        print("create socket failed")
        print(e)
        sys.exit()
    print("socket created")
    server_address = ('192.168.137.240', 12345)
    sk.bind(server_address)
    sk.listen(5)    # listen(5) tức là

    print("waiting...")
    while True:
        client_sk, client_address = sk.accept()
        print(f'Client address: {client_address}')
        print(f'Client Socket: {client_sk}')
        client_sk.send('hello client'.encode('utf-8'))
        client_sk.close()
        break

