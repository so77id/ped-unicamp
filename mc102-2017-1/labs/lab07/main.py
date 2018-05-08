# -*- coding: utf-8 -*-

def tupla_float_int(x) :
    x = x[1:-1]       # remove parênteses
    x = x.split(",")  # separa em duas strings
    f = float(x[0])   # converte primeiro elemento para float
    i = int(x[1])     # converte segundo elemento para int
    return (f,i)      # retorna tupla

def mean(array):
    quantity = len(array)
    sum = 0.0
    for element in array:
        sum += element

    return sum/quantity

def weighted_mean(array):
    sum = 0.0
    weights = 0

    for pair in array:
        weights += pair[1]
        sum += pair[0] * pair[1]

    return sum/weights

notas_ac = [float(x) for x in input().split()]
media_ac = mean(notas_ac)

notas_lab = [tupla_float_int(x) for x in input().split()]
media_lab = weighted_mean(notas_lab)

probas = input().split()

nota_proba1 = float(probas[0])
nota_proba2 = float(probas[1])
media_probas = (nota_proba1 * 2.0 + nota_proba2 * 3.0)/5.0

freq = float(input())



media_elementos = 0.6 * media_probas + 0.3 * media_lab + 0.1 * media_ac
media_preliminar = min(media_elementos, media_probas, media_lab)

print("Média das atividades conceituais:", format(media_ac, ".1f"))
print("Média das tarefas de laboratório:", format(media_lab, ".1f"))
print("Média das provas:", format(media_probas, ".1f"))
print("Média ponderada dos elementos:", format(media_elementos, ".1f"))
print("Média preliminar:", format(media_preliminar, ".1f"))

if freq >= 75:
    if media_preliminar >= 5.0:
        media_final = media_elementos
        print("Aprovado(a) por nota e frequência.")
    elif media_preliminar >= 2.5:
        nota_examen = float(input())
        print("Nota no exame:", format(nota_examen, ".1f"))
        media_final = (nota_examen + media_preliminar)/2
        if media_final >= 5.0:
            print("Aprovado(a) por nota e frequência.")
        else:
            print("Reprovado(a) por nota.")
    else:
        media_final = media_preliminar
        print("Reprovado(a) por nota.")
else:
    media_final = media_preliminar
    print("Reprovado(a) por frequência.")

print("Média final:", format(media_final, ".1f"))
