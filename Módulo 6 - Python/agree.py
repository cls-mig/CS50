s = input("Você concorda comigo? ")

# os operadores lógicos são literalmente escritos, não possuem símbolos próprios
# em python não há diferenças entre aspas simples e aspas duplas
# if s == 'S' or s == 's':

if s.lower() in ["s", "sim"]:
    print("Certo!")
elif s.lower() in ["n", "nao", "não"]:
    print("Reconcidere!")
else:
    print("Responda minha pergunta.")
