import virfunc


class Derived(virfunc.Base):
    @staticmethod
    def f():
        return 456


if __name__ == '__main__':
    b = virfunc.Base()
    d = Derived()
    virfunc.calls_f(b)
    virfunc.calls_f(d)
