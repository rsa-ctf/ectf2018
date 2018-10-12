from primes import ps, qs
from rsasim.gcd_utils import inverse
message = "i am become admin, the controller of this server"

admins = []

e = 65537
ps = [long(p) for p in ps]
qs = [long(q) for q in qs]

for p,q in zip(ps, qs):
    n = long(p * q)
    phi = long((p - 1) * (q - 1))
    d = long(inverse(e, phi))
    admins.append({"p": long(p), "q": long(q), "e": long(e), "d": d, "n":n})

import json

with open("admindata.json", "w") as f:
    json.dump(admins, f)

