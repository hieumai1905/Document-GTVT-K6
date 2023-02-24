import BaseModule

host = BaseModule.host
port = BaseModule.port


def client_process(sk, addr):
    try:
        # Nhân message
        msg = BaseModule.recv_msg(sk)
        if msg == 'q':
            sk.close()
            return
        print("{}:{}".format(addr, msg))
        BaseModule.send_msg(sk, msg)
    except (ConnectionError, BrokenPipeError):
        print("Socket error")
    # finally:
    #     sk.close()


if __name__ == '__main__':
    sk = BaseModule.create_socket(host, port)
    sk.bind((host, port))
    sk.listen(10)
    addr = sk.getsockname()
    print("Listent on local port {}".format(addr))
    while True:
        client_sk, addr = sk.accept()
        print("Connection from {}".format(addr))
        client_process(client_sk, addr)
