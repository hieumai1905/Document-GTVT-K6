def handle_space(s):
    s = s.strip()
    list = s.split(' ')
    while '' in list:
        list.remove('')
    res = ' '.join(list)
    return res
def handle_coma(s):
    s = s.strip()
    list = s.split(',')
    res = []
    for i in list:
        res.append(handle_space(i))
    return ', '.join(res)
def handle_dot(s):
    s = s.strip()
    list = s.split('.')
    res = []
    for i in list:
        res.append(handle_coma(i).capitalize())
    return '. '.join(res)
if __name__ == '__main__':
    s = 'hom Nay thoi   tiET THe nAO vA   hom nay  , la mot    NGAY rat  lA dEp   . DuNg vay  .    Qua la   ,     nGaY DEP tRoi!'
    print(s)
    print(handle_dot(s))
