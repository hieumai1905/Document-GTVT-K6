import socket

hostname = socket.gethostname()
ip = socket.gethostbyname(hostname)
print("Hostname: ", hostname)
# hostname là tên máy tính
print("IP: ", ip)
# khi ip trả về 127.0.1 nghĩa là máy tính không có kết nối mạng
