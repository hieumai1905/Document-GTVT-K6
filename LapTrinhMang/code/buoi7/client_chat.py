import socket


def Main():
    host = '192.168.0.12'
    port = 11223

    s = socket.socket()
    s.connect((host, port))

    message = input("-> ")
    while message != 'q':
        s.send(message.encode('utf-8'))
        data = s.recv(4096).decode('utf-8')
        print("Received from server: " + data)
        message = input("-> ")
    s.close()


if __name__ == '__main__':
    Main()
