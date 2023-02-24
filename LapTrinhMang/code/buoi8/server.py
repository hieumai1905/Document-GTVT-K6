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
    sk.bind(address_server)
    sk.listen(5)
    print('Waiting client...')

    sk_client, address_client = sk.accept()
    print(f'socket client: {sk_client}')
    print(f'address client: {address_client}')
    message = 'hello client'
    sk_client.send(message.encode('utf-8'))

    file_name = sk_client.recv(4096).decode('utf-8')

    try:
        with open(file_name, 'rb') as f:
            file_content = f.read()
            sk_client.send(file_content)
    except FileNotFoundError:
        sk_client.send(b'File not found')


if __name__ == '__main__':
    Main()
