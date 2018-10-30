import datamems

if __name__ == '__main__':
    x = datamems.Var('pi')
    x.value = 3.14
    print x.name, 'is around', x.value
