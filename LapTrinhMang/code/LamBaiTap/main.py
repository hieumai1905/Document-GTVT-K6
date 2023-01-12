import requests
from bs4 import BeautifulSoup

if __name__ == '__main__':
    url = 'https://forecast.weather.gov/MapClick.php?lat=36.693760000000054&lon=-121.62482999999997#.Y79Q_HbP2Ht'
    headers = requests.utils.default_headers()
    response = requests.get(url, headers)
    soup = BeautifulSoup(response.content, 'html.parser')

    # tags = soup.find_all('li', attrs={'class': 'forecast-tombstone'})
    tags = soup.find_all('div', class_='tombstone-container')
    for tag in tags:
        name = tag.find('p', attrs={'class': 'period-name'}).text
        print('name: '.format(name))
    print(tags)
