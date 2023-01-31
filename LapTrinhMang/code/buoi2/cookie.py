from urllib.request import urlopen
from urllib.request import build_opener, HTTPCookieProcessor
from http.cookiejar import CookieJar
import datetime

if __name__ == '__main__':
    # tao khong gian luu tru cookie
    cookie = CookieJar()
    # tu dong lay cookie thong qua urllib.builder
    opener = build_opener(HTTPCookieProcessor(cookie))
    opener.open("http://www.github.com")
    print(len(cookie))
    cookies = list(cookie)
    print(cookies)
    print(cookies[0].name)
    print(cookies[0].expires)
    print(datetime.datetime.fromtimestamp(cookies[0].expires))


