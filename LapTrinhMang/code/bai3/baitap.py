import requests

from bs4 import BeautifulSoup

if __name__ == '__main__':
    headers = requests.utils.default_headers()
    url = 'https://forecast.weather.gov/MapClick.php?lat=36.693760000000054&lon=-121.62482999999997#.Y79Q_HbP2Ht'
    req = requests.get(url, headers)
    soup = BeautifulSoup(req.content, 'html.parser')
    tags = soup.findAll('div', class_='tombstone-container')
    tags = tags[1:]
    for tag in tags:
        title = tag.find('p', class_='period-name').text
        print('title: ' + title)
        url_img = tag.find('img').attrs['src']
        print('url_img: ' + url_img)
        name = tag.find('p', class_='short-desc').text
        print('name: ' + name)
        temp = tag.find('p', class_='temp').text
        print('temp: ' + temp + '\n')
