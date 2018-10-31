import vf


class Derived(vf.Base):
    @staticmethod
    def f():
        return 456


if __name__ == '__main__':
    b = vf.Base()
    d = Derived()
    vf.calls_f(b)
    vf.calls_f(d)
