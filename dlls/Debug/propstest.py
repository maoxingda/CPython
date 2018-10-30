import props

if __name__ == '__main__':
    x = props.Num()
    x.value = 3.14
    print x.value, x.rovalue

    x.rovalue = 2.17  # can not change read only attribute
