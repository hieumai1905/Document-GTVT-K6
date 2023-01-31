from urllib.request import urlopen

if __name__ == '__main__':
    url = 'https://www.google.com.vn/?hl=vi'
    # Gửi HTTP GET tới url để lấy dữ liệu
    response = urlopen(url)
    html = response.read()
    headers = response.getheaders("Content-Type")
    status = response.getcode()
    print(html)
    print(headers)
    print(status)
