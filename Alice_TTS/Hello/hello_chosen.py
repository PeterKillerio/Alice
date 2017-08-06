from Hello import hello_listread
from random import randint

hello_index = randint(0, len(hello_listread.hello_list)-1)

greeting_modified = hello_listread.hello_list[hello_index].replace('\n', ' ')