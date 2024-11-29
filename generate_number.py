import random

def generate_random_list(n, lower_bound=-10000, upper_bound=10000):

    if n <= 0:
        return []
    unique_numbers = set()

    while len(unique_numbers) < n:
        num = random.randint(lower_bound, upper_bound)
        unique_numbers.add(num)

    return list(unique_numbers)


random_list = generate_random_list(1000)
print(" ".join(map(str, random_list)))