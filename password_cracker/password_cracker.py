import hashlib
user_hash_dict={}


with open('common_passwords.txt','r') as f:
    common_passwords =f.read().splitlines()

with open('username_hashes.txt','r') as f:
    text=f.read().splitlines()
    for user_hash in text:
        username=user_hash.split(":")[0]
        hash=user_hash.split(":")[1]
        user_hash_dict[username]=hash

# 딕션너리에 잘들어 갔는지 확인
for user,hash in user_hash_dict.items():
    print(user,hash)

for password in common_passwords:
    hashed_password=hashlib.sha256(password.encode('utf-8')).hexdigest()
    for username, hash in user_hash_dict.items():
        if hashed_password ==hash:
            print(f"HASH FOUND\n{username}:{password}!")

