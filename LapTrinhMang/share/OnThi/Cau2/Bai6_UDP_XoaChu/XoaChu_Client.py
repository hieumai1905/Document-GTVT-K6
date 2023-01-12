import socket
host = '127.0.0.1'
port = 5051

if __name__ == '__main__':
    sk = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    msg = input("Nhập chuỗi: ")
    sk.sendto(msg.encode('utf-8'), (host,port))

    data, addr = sk.recvfrom(1024)
    print(data.decode('utf-8'))
