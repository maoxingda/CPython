import virfunc


class Derived(virfunc.Base):
    def f(self):
        return 42


if __name__ == '__main__':
    b = virfunc.Base()
    d = Derived()
    # b.f()
    print d.f()
