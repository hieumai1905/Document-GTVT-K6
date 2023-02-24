import socket
import BaseModule

host = BaseModule.host
port = BaseModule.port

if __name__ == '__main__':
    sk = BaseModule.create_socket(host, port)
    sk.connect((host, port))
    while True:
        try:
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
