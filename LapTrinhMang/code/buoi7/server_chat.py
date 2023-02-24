import socket


def Main():
    host = '192.168.0.12'
    port = 11223

    s = socket.socket()
    s.bind((host, port))
    s.listen(1)
    conn, addr = s.accept()
    print("Connection from: " + str(addr))
    while True:
        data = conn.recv(1024).decode('utf-8')
        if not data:
            break
        print("From connected user: " + data)
        message = input("-> ")
        conn.send(message.encode('utf-8'))
    conn.close()


if __name__ == '__main__':
    Main()
