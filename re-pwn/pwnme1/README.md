# Challenge: pwnme1

# Points: 50

# Description: 

Do you know about links?

Executable: [Link1](./pwnme1)
Sourcefile: [Link2](,/pwnme1.c)



You can login at ectf.nitk.ac.in: 30100 - We have to set this up!

NOTE TO US: 


2. While setting up, the user of **pwnme1** executable should be **pwnme1** it should be setuid to **pwnme1_pwn**. 

3. This is how convert pwnme1 into a setuid executable: 

a. Create 2 users with names **pwnme1** and **pwnme1_pwn**. . 
b. Change the owner of pwnme1-executable to **pwnme1_pwn** - chown pwnme1_pwn pwnme1
c. Change the group of pwnme1-executable to **pwnme1** - chgrp pwnme1 pwnme1
d. Set the setuid bit: chmod u+s pwnme1

So, a user with pwnme1 prvileges can also run executables with pwnme1_pwn(higher privileges) and get a shell with higher privileges to read **flag.txt** . 

4. There is a flag.txt with user **pwnme1_pwn** and group **pwnme1_pwn**. So, only with the shell with privileges **pwnme1_pwn**, one will be able to read flag.txt.

4. With tha flag.txt, the following should be done to ensure only **pwnme1_pwn** user is able to read it and no one else. 

$ sudo chmod 0400 flag.txt  - Damn Important because in normal cases, "others" are allowed to read files owned by higher-privilege-users but this should happne in our case. 

This is very very important!


