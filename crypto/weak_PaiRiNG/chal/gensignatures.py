from Crypto.PublicKey import RSA
from Crypto.Signature import PKCS1_v1_5
from Crypto.Hash import SHA
import base64
import json

message = "I am become admin, the owner of this server"
hashval = SHA.new(message)
valid_signatures = []

with open("admindata.json") as f:
    admindata = json.load(f)

for admin in admindata:
    params = (admin["n"], admin["e"], admin["d"], admin["p"], admin["q"])
    longparams = (long(param) for param in params)
    key = RSA.construct(longparams)
    signer = PKCS1_v1_5.new(key)
    signature = signer.sign(hashval)
    pub = key.publickey()
    print(signer.verify(hashval, signature))
    valid_signatures.append(base64.b64encode(signature))

with open("signatures.json", "w") as f:
    json.dump(valid_signatures, f)
