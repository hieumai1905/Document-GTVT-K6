# tao request de gui den server
from urllib.request import urlopen, Request
import urllib.error

if __name__ == '__main__':
    # xu ly loi
    try:
        # tao request
        req = Request("http://www.google.com")

        # them header cho request
        req.add_header("Accept-Encoding", "gzip")

        # mo ket noi su dung urllib
        response = urlopen(req)

        # kiem tra header
        print(response.getheader("Content-Encoding"))
        print(response.read())
        # -> 200 if true else 404
    except urllib.error.HTTPError as e:
        print(e.code)
    except urllib.error.URLError as e:
        print(e.reason)
