
import math

enum = 1_213_432_333_743_539_155
denom = 5_923_746_191_783_711_543
print(f"Fraction = {enum} / {denom}")

def prime_factors(n: int) -> list[tuple[int, int]]:
    """ Get the prime factors of n, with their powers. Returns a list of tuples
        (prime, power) """
    factors: list[tuple[int, int]] = []
    p = 2
    while n > 1:
        count = 0
        while n % p == 0:
            count += 1
            n //= p
        if count > 0:
            factors.append((p, count))
        p += 1
    return factors

def divisors(n: int) -> list[int]:
    """ All divisors of a number """
    divs = set([1])
    for prime, count in prime_factors(n):
        next_divs: set[int] = set()
        for power in range(count + 1):
            next_divs = next_divs.union([x * (prime ** power) for x in divs])
        divs = next_divs
    return list(divs)

def phi(n: int) -> int:
    """ Euler totient function """
    total = 1
    for prime, count in prime_factors(n):
        total *= prime ** (count - 1) * (prime - 1)
    return total

# USED FOR DEBUGGING
def fraction_digits(enum: int, denom: int) -> str:
    """ All decimal digits of a fraction, assumes the fraction is less than 1
        and both enum and denom are strictly positive. Any repeating digits at
        the end are denoted with (repeating part) """
    out = "0."
    # Map from seen remainder to index
    seen: dict[int, int] = {}
    rem = enum
    while rem not in seen:
        seen[rem] = len(out)
        rem *= 10
        out += str(rem // denom)
        rem %= denom
    index = seen[rem]
    return out[:index] + "(" + out[index:] + ")"
# Reduce fraction, not necessary in this case because gcd(ENUM, DENOM) = 1
enum, denom = enum // math.gcd(enum, denom), denom // math.gcd(enum, denom)

# Filter out any factors 2 and 5, which for this problem wasn't necessary since
# denominator isn't divisible by 2 or 5
while denom % 2 == 0:
    denom //= 2
while denom % 5 == 0:
    denom //= 5

# Need to find lowest number n such that 10^n % denom = 1
# By Euler's theorem, we know 10^phi(denom) % denom = 1 (10 and denom are
# coprime), which means n is a divisor of denom
t = phi(denom)
lo = t
print("phi(reduced denom) =", t)
print("factors(phi(reduced denom)) =", prime_factors(t))
c = 0
for div in divisors(t):
    if pow(10, div, denom) == 1:
        lo = min(lo, div)
    c += 1
print("number of divisors =", c)
print("repeating digits length =", lo)
# print(len(fraction_digits(enum, denom).split("(")[1]) - 1)
