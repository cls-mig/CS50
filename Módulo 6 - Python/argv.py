from sys import argv

if len(argv) == 2: # len me informa o comprimento dessa lista (ou seja, do argv)
    print(f"hello, {argv[1]}")
    # python argv.py David - python é o interpretador (não faz parte da execução)
else:
    print("hello, world")
'''
for arg in argv:
    print(arg)
'''
