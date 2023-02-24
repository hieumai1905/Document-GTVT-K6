import socket


def handle(s):
    # chuyển chuỗi s về dạng chuẩn của một chuỗi. Trong đó loại bỏ các khoảng trắng ở đầu và cuối chuỗi, các ký tự sau dấu chẩm phải viết hoa và cách ra 1 khoảng trắng, và sau dấu chấm phải có 1 khoảng trắng
    s = s.strip()
    s = s.title()
    s = s.replace('.', '. ')
    s = s.replace('  ', ' ')

    return s

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
    message = 'Hello client'
    sk_client.send(message.encode('utf-8'))

    s = sk_client.recv(4096).decode('utf-8')
    print(s)

    sk_client.sendall(handle(s).encode('utf-8'))
    sk_client.close()
    s.close()


if __name__ == '__main__':
    Main()
