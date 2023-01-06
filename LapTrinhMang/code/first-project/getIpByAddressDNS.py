import socket

if __name__ == '__main__':
    # nameDNS = 'python.org'
    # nameDNS = 'google.com'
    nameDNS = socket.gethostname()
    ipDNS = socket.gethostbyname(nameDNS)
    print("Hostname: ", nameDNS + "\nIP: ", ipDNS)


