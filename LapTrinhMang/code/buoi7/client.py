import socket

# tạo một socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM, proto=0, fileno=None)
# proto là giao thức mạng được sử dụng để truyền dữ liệu, mặc định là 0
# fileno nghĩa là file number (mã số file) là một số nguyên duy nhất được gán cho mỗi file mở trong hệ thống. Nó được sử dụng để xác định một file mở trong hệ thống.

# kết nối tới server
server_address = ('172.20.10.2', 12345)
try:
    s.connect(server_address)
except socket.error as e:
    print('Error: ', e)
    exit()

# gửi dữ liệu
data = 'Hello server'
s.sendall(data.encode('utf-8'))  # chuyển dữ liệu thành dạng bytes

# đóng kết nối
s.close()
