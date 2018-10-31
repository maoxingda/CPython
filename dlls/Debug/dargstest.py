import dargs

f = dargs.f

if __name__ == '__main__':
    print f(), f(1)
    g = dargs.george()
    g.wack_em(1)
    g.wack_em(1, 2)
    g.wack_em(1, 2, 'y')
