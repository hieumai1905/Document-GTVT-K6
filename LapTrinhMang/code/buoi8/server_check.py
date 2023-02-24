import socket


def Main():
    global sk
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

    while True:
        sk_client, address_client = sk.accept()
        data = sk_client.recv(4096).decode('utf-8')
        if data == 'bye':
            print('New client')
            sk_client, address_client = sk.accept()
            print(f'socket client: {sk_client}')
            print(f'address client: {address_client}')
            print('----------------------------------')
            continue
        if data == 'time':
            import datetime
            time = datetime.datetime.now().strftime('%H:%M:%S')
            sk_client.send(time.encode('utf-8'))
        else:
            sk_client.send('I do not understand'.encode('utf-8'))


if __name__ == '__main__':
    Main()
