import gzip
from http.cookiejar import CookieJar
from urllib.request import Request, urlopen, build_opener, HTTPCookieProcessor

if __name__ == '__main__':
    # Tạo một request bằng urlopen
    req = Request("http://www.google.com")
    response = urlopen(req)
    print(req)
    print(response.read())

    # them header cho request
    req.add_header("Accept", "application/json")
    print(req.get_header("Accept"))

    # nen du lieu
    req.add_header("Accept-Encoding", "gzip")

    data = gzip.decompress(response.read())
    print(data)
    response = gzip.compress(data)
    print(response.splitlines()[:5])

    # user agent có tác dụng giả mạo trình duyệt của người dùng. Nếu không có user-agent thì server sẽ trả về 403
    req1 = Request("http://www.github.com")
    req1.add_header("User-agent", "Mozilla/5.0")
    print(req1.get_header("User-agent"))

    # cookie là một chuỗi dữ liệu được gửi từ server đến client và được lưu trữ trên máy tính của client.
    # Cookie được sử dụng để lưu trữ thông tin về người dùng và các thiết lập của người dùng.

    # tao khong gian luu tru cookie va lay trong khong gian luu tru cookie_jar
    cookie = CookieJar()

    # lay cookie tuong tac voi server
    opener = build_opener(HTTPCookieProcessor(cookie))

    # tao request
    opener.open("http://www.github.com")
    print(len(cookie))

    # tao danh sach cookie
    cookies = list(cookie)
    print(cookies, sep="\n")
