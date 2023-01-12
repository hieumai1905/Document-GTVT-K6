import ipaddress as ip

# 192.168.0.0/25
# neu /25 muon 1 -> 2^7 thi 128 - 2, neu / 26 muon 2 -> 2^6 thi 64 - 2

if __name__ == '__main__':
    class_c = '192.168.0.0'
    source = int(input("Enter prefix (24-30): "))
    if (source not in range(24, 31)):
        raise Exception("Prefix must be in range 24-30")
    network_address = class_c + '/' + str(source)
    print(f'Netword address: {network_address}')

    try:
        network = ip.ip_network(network_address)
    except:
        raise Exception("Invalid network address")
    print(f'Network address: {network.num_addresses}')
    print(f'Network Information')
    print(f'\tNetmask: {network.netmask}')
    print(f'\tBroadcast address: {network.broadcast_address}')
    print(f'\tHosts 0: {list(network.hosts())[0]} - Hosts 1: {list(network.hosts())[-1]}')
    # hien thi cac host tren tung dong

