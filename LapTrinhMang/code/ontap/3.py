from urllib.request import Request, urlopen

if __name__ == '__main__':
    url = 'https://www.google.com.vn/?hl=vi'
    # tạo đối tượng request
    req = Request(url)
    # thêm header
    req.add_header('User-Agent', 'Mozilla/5.0')
    # mở kết nối
    response = urlopen(req)
    print(response.read())
