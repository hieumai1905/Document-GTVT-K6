import socket
import sys # sys.exit() dùng để thoát khỏi chương trình

# tạo một socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM, proto=0, fileno=None)

# liên kế socket với một địa chỉ và cổng
server_address = ('172.20.10.2', 12345)
s.bind(server_address) # bind() liên kết một socket với một địa chỉ và cổng

# lắng nghe kết nối
s.listen(5) # listen() lắng nghe kết nối đến socket

# chấp nhận kết nối
client_socket, client_address = s.accept() # accept() chấp nhận kết nối đến socket
print(client_socket)
print(client_address)

# nhận dữ liệu
data = client_socket.recv(1024).decode('utf-8') # recv() nhận dữ liệu từ socket
print(data)

# đóng kết nối
client_socket.close()
s.close()
