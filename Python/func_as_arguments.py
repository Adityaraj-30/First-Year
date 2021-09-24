# list=['car','bike','bus','scooter']

# def loop(x):
#     print(x*3)

# loop (list)

list=['car','bike','bus','scooter']

def loop(x):
    print(x*3)

def map_simple(crazy,list):
    for items in list:
        crazy(items)

map_simple(loop,list)        