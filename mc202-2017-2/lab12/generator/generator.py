
import random


path = "../testes_fechados"
init_example = 0
n_examples = 10
MAX_F = 10000
MIN_F = 1
MAX_KG = 1000000


fruits = ["apple", "pear", "banana", "plantain", "grape", "orange", "lemon",
          "lime", "grapefruit", "strawberry", "raspberry", "blackberry",
          "blueberry", "cranberry", "kiwi", "pineapple", "watermelon", "melon",
          "cantaloupe", "cucumber", "papaya", "mango", "coconut", "pomegranate",
          "peach", "nectarine", "apricot", "avocado", "tomato"]

def new_product(kg_min=1, kg_max=MAX_KG):
    fruit = random.choice(fruits)
    kg = random.randint(kg_min, kg_max)

    return fruit, kg


for i in range(init_example, n_examples):
    filename = "%s/arq%02d.in" % (path, i + 1)
    f_min = min(max(2**(i+5), MIN_F), MAX_F)
    f_max = min(int(2**(i+8)), MAX_F)
    kg_min = 1
    kg_max = min(int(2**(i+8)), MAX_KG)
    print("filename: {}".format(filename))
    print "fruits --> min: {} max: {}".format(f_min, f_max)
    print "kg --> min: {} max: {}".format(kg_min, kg_max)


    n_fruits = random.randint(f_min, f_max)

    with open(filename, 'w') as file:
        kgs = {}
        for j in range(n_fruits):
            fruit = random.choice(fruits)

            kg = random.randint(kg_min, kg_max)
            while kg in kgs:
                kg = random.randint(kg_min, kg_max)
            kgs[kg] = kg

            file.write("{} {}\n".format(fruit, kg))
        file.write("#\n")
