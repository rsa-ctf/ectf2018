# Challenge: wowlibc

<<<<<<< HEAD
# Points: 100
=======
# Points: 125
>>>>>>> 9d147b6875e430acce3ca1c3ac35f35441aeed93

# Description: 

Get it!
Look at [this](./wowlibc) executable. 
[This](./wowlibc.c) is the sourcefile. 

# Hint: 

1. This might look like shellcode, but it doesn't work. 
2. Think why is that and try to break it!

NOTE TO US:


2. While setting up, the user of **wowlibc** executable should be **wowlibc** it should be setuid to **wowlibc_pwn**.

3. This is how convert wowlibc into a setuid executable:

a. Create 2 users with names **wowlibc** and **wowlibc_pwn**. .
b. Change the owner of wowlibc-executable to **wowlibc_pwn** - chown wowlibc_pwn wowlibc
c. Change the group of wowlibc-executable to **wowlibc** - chgrp wowlibc wowlibc
d. Set the setuid bit: chmod u+s wowlibc

So, a user with wowlibc prvileges can also run executables with wowlibc_pwn(higher privileges) and get a shell with higher privileges to read **flag.txt** .

4. There is a flag.txt with user **wowlibc_pwn** and group **wowlibc_pwn**. So, only withthe shell with privileges **wowlibc_pwn**, one will be able to read flag.txt.

5. With tha flag.txt, the following should be done to ensure only **wowlibc_pwn** user is able to read it and no one else.

$ sudo chmod 0400 flag.txt  - Damn Important because in normal cases, "others" are allowed to read files owned by higher-pri
vilege-users but this should happne in our case.

This is very very important!
