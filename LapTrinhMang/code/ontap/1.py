import socket

if __name__ == '__main__':
    # lấy ra tên miền của máy tính
    nameDNS = socket.gethostname()
    print(nameDNS)

    # lấy ra địa chỉ của máy từ tên miền
    IP = socket.gethostbyname(nameDNS)
    print(IP)
