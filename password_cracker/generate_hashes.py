import hashlib

password ="manduisgood"
hash= hashlib.sha256(password.encode('utf-8'))
print(hash.hexdigest())