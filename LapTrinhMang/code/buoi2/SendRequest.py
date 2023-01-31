from urllib.request import Request

import requests as requests

if __name__ == '__main__':


    query = {
        'q': 'river', 'oder': 'popular', 'min_width': '1000', 'min_height': '1000'
    }

    url = 'https://pixabay.com/en/photos'

    r = requests.get(url, params=query)

    print(r.url)
