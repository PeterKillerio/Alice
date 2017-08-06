
hello_file = 'Hello/hello.txt'


hello_cont = open(hello_file, 'r')

hello_list= []

for line in hello_cont:
    hello_list.append(line)
