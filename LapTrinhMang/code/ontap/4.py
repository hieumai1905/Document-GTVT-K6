from urllib.request import Request, urlopen

if __name__ == '__main__':
    url = "https://www.example.com/api/post_data"
    data = b"data_to_post"
    req = Request(url, data=data, method='POST')
    response = urlopen(req)
    html = response.read()
    print(html)
