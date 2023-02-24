import socket

# Tạo một socket object
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Lấy địa chỉ IP và cổng của server
host = socket.gethostbyname(socket.gethostname())
port = 12345

# Kết nối tới server
client_socket.connect((host, port))

# Yêu cầu danh sách tất cả các file
client_socket.send("list".encode())

# Nhận danh sách tất cả các file
file_list = eval(client_socket.recv(1024).decode())
# eval() sẽ chuyển đổi chuỗi thành một đối tượng Python

# In danh sách tất cả các file
print(file_list)

# Nhập tên file cần tải
file_name = input("Enter file name to download: ")

# Gửi yêu cầu để tải file
client_socket.send(file_name.encode())

# Nhận thông báo về tình trạng của file
status = client_socket.recv(1024).decode()

if status == "exists":
    # Nhận nội dung file
    content = client_socket.recv(1024)

    with open("download/" + file_name, "wb") as f:
        f.write(content)
        print("File downloaded successfully")

else:
    print("File not found")
