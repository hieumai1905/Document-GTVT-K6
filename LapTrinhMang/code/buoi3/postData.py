import requests

if __name__ == '__main__':
    url = 'https://github.com/login'
    user = {
        'login': 'hieumai1905',
        'password': 'maivanhieu1905'
    }
    req = requests.post(url, data=user)
    print(req.status_code)
    cookie = req.cookies.get_dict()
    print(cookie)
