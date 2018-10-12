# Challenge: pwnme0

# Points: 20

# Description: 

Get the flag!
Executable: [Link1](./pwnme0)
Sourcefile: [Link2](,/pwnme1.c)

NOTE TO US: 

1. This program is just present to understand what "/bin/sh" is, what system is, what setuid executable is. 

2. While setting up, the user of **pwnme0** executable should be **pwnme0** it should be setuid to **pwnme0_pwn**. 

3. This is how convert pwnme0 into a setuid executable: 

a. Create 2 users with names **pwnme0** and **pwnme0_pwn**. . 
b. Change the owner of pwnme0-executable to **pwnme0_pwn** - chown pwnme0_pwn pwnme0
c. Change the group of pwnme0-executable to **pwnme0** - chgrp pwnme0 pwnme0
d. Set the setuid bit: chmod u+s pwnme0

So, a user with pwnme0 prvileges can also run executables with pwnme0_pwn(higher privileges) and get a shell with higher privileges to read **flag.txt** . 

4. There is a flag.txt with user **pwnme0_pwn** and group **pwnme0_pwn**. So, only with the shell with privileges **pwnme0_pwn**, one will be able to read flag.txt.

4. With tha flag.txt, the following should be done to ensure only **pwnme0_pwn** user is able to read it and no one else. 

$ sudo chmod 0400 flag.txt  - Damn Important because in normal cases, "others" are allowed to read files owned by higher-privilege-users but this should happne in our case. 

This is very very important!







