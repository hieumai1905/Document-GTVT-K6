import socket
import Buoi11_BaseModule

host = BaseModule.host
port = BaseModule.port
if __name__ == '__main__':
    while True:
        try:
            sk = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            sk.connect((host, port))
            print("Enter message (q to exit:) ")
            msg = input()
            BaseModule.send_msg(sk, msg)
            if msg == 'q':
                break
            print("Send: {}".format(msg))
            # Nhận về
            msg = BaseModule.recv_msg(sk)
            print("Receive: " + msg)
        except ConnectionError:
            print("Socket error")
            break
        finally:
            sk.close()
