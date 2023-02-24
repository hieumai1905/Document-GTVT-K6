import socket

def Main():
    try:
        sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        print('create socket success')
    except:
        print('socket create error')
    host = socket.gethostbyname(socket.gethostname())
    port = 12344

    address_server = (host, port)
    try:
        sk.connect(address_server)
        print('connect to server success')
    except:
        print('connect to server error')

    data = sk.recv(4096).decode('utf-8')
    print(data)

    message = input('-> ')
    sk.sendall(message.encode('utf-8'))
    data = sk.recv(4096).decode('utf-8')
    print(f'Sever->: {data}')


if __name__ == '__main__':
    Main()
