import string
import random
import numpy as np

first_names = ["ANTONIO", "JOSE", "MANUEL", "JAVIER", "JESUS", "FRANCISCO", "CARLOS", "DANIEL", "MIGUEL", "RAFAEL", "JOSE", "ANGEL", "JORGE", "ALBERTO", "JUAN", "JOSE", "RAMON", "ENRIQUE", "DIEGO", "ANTONIO", "VICENTE", "ALVARO", "RAUL", "ADRIAN", "JOAQUIN", "IVAN", "ANDRES", "MARIA", "CARMEN", "JOSEFA", "ISABEL", "ANA", "LAURA", "FRANCISCA", "ANTONIA", "DOLORES", "ANGELES", "LUCIA", "CONCEPCION", "ELENA"]
last_names = ["TRIVEZ", "RIPADO", "BALDOR", "DANUS", "BOHER", "DEBLAS", "SANTAOLAYA", "ORTIZ", "DIAZ", "GOITIZ", "DELEITO", "COCINERO", "ASCARZA", "IPAS", "OJOPI", "VEA", "SOSTRES", "BONAVILA", "MATAMORO", "CARGUA", "SARSA", "ALBITE", "CHANTRERO", "SOTO", "PURTI", "MUSET", "TERESA", "ABEJARO", "JARIEGO"]

first_names = np.array(first_names)
last_names = np.array(last_names)

def id_generator(size=6, chars=string.ascii_uppercase + string.digits):
    return ''.join(random.choice(chars) for _ in range(size))


max_stocks = 100
max_variations = 20
examples = 30

def clip(n, max):
    if n>max:
        return max
    else:
        return n

def gen(path, reduction=1):
    for i in range(examples):
        filename = "%s/arq%02d.in" % (path,i + 1)
        print(filename)

        with open(filename, 'w') as file:
            perc_d = (i/examples)/reduction
            perc_t = (i/examples)/reduction + 0.2

            i_name = random.randint(0, first_names.shape[0]-1)
            i_last = random.randint(0, last_names.shape[0]-1)
            n_stocks = random.randint(int(max_stocks * perc_d), int(max_stocks * perc_t))
            n_stocks = clip(n_stocks, max_stocks)

            s = "{} {} {}\n".format(first_names[i_name].capitalize(), last_names[i_last].capitalize(), n_stocks)
            file.write(s)

            for j in range(n_stocks):
                size_name = random.randint(4, 10)
                initial_investment = random.uniform(100.00, 1000000.00)
                variations = random.randint(1, max_variations)
                stock_s = "{} {} {}".format(id_generator(size_name), "{0:.2f}".format(initial_investment), variations)

                for v in range(variations):
                    var = random.uniform(-30.00, 30.00)
                    stock_s = "{} {}".format(stock_s, "{0:.2f}".format(var))
                stock_s = "{}\n".format(stock_s)
                file.write(stock_s)

gen("../testes_abertos")
