
jokes_file = 'Joke/jokes.txt'


jokes_cont = open(jokes_file, 'r')

jokes_list= []

for line in jokes_cont:
    jokes_list.append(line)
