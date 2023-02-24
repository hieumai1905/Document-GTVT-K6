import socket
import sys

if __name__ == '__main__':
    try:
        sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    except socket.error as e:
        print("create socket failed")
        print(e)
        sys.exit()
    print("socket created")
    try:
        # host_name = socket.gethostname()
        # host_ip = socket.gethostbyname(host_name)
        # host_ip = input()
        # host_port = input()
        server_address = ('192.168.137.240', 12345)
        sk.connect(server_address)
        print("socket connected")
    except socket.error as e:
        print("connect to server failed")
        print(e)
        sys.exit()

    while True:
        data = 'hello server'
        sk.sendall(data.encode('utf-8'))

        data = sk.recv(1024).decode('utf-8')
        print(data)
        break

    sk.close()
