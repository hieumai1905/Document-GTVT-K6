import os
import socket

# Tạo một socket object
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Lấy địa chỉ IP và cổng của server
host = socket.gethostbyname(socket.gethostname())
port = 12345

# Bind socket object với địa chỉ IP và cổng
server_socket.bind((host, port))

# Lắng nghe kết nối đến từ client
server_socket.listen(5)

while True:
    # Chấp nhận kết nối đến từ client
    client_socket, addr = server_socket.accept()

    # Nhận yêu cầu từ client
    request = client_socket.recv(1024).decode()

    if request == "list":
        # Lấy danh sách tất cả các file trong thư mục hiện tại của server
        files = os.listdir()
        # os.listdir() sẽ trả về một list chứa tên tất cả các file trong thư mục

        # Gửi danh sách tất cả các file về cho client
        client_socket.send(str(files).encode())

        # Nhận yêu cầu từ client để tải file
        request = client_socket.recv(1024).decode()

        # Kiểm tra xem file có tồn tại không
        if request in files:
            # Gửi thông báo cho client rằng file tồn tại
            client_socket.send(b"exists")

            # Mở file và đọc nội dung
            with open(request, "rb") as f:
                content = f.read()

            # Gửi nội dung file về cho client
            client_socket.send(content)

        else:
            # Gửi thông báo cho client rằng file không tồn tại
            client_socket.send(b"not exists")

    # Đóng socket của client
    client_socket.close()
